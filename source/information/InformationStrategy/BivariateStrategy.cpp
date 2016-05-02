#include "BivariateStrategy.hpp"
#include <iostream>


BivariateStrategy::BivariateStrategy(): error_matrix_(new MatrixCalculator()), solver_(new InformationRootFinder()), information_calculator_(new BiInformationCalculator()), 
										kd1_(0), kd2_(0), kd3_(0) {}

BivariateStrategy::~BivariateStrategy()
{
	delete error_matrix_;
	delete solver_;
	delete information_calculator_;
}

void BivariateStrategy::assignateKD(InformationProteinsContainer* data)
{
	std::vector<double> one_sided_kds = data->getOneSidedComplexesDissociationConstant(BIONESIDEDCOMPLEXSIZE);
	kd1_ = one_sided_kds.at(0);
	kd2_ = one_sided_kds.at(1);
	kd3_ = data->getWholeCommunicationComplexDissociationConstant(BICOMMUNICATIONSYSTEMSIZE);
}

void BivariateStrategy::calculateMutualInformation(std::vector<double> concentrations)
{	
	information_calculator_->setConcentrations(concentrations);
	information_calculator_->calculateMutualInformation();
}

void BivariateStrategy::initiateSolver(InformationProteinsContainer* data)
{
	solver_->initiateFunction(data->getChannelConcentration(), data->getInputConcentration(), data->getOutputConcentration(), kd1_, kd2_, kd3_);
}

void BivariateStrategy::calculateErrorMatrix(std::vector<double> concentrations)
{
	error_matrix_->calculateError(concentrations);
}

void BivariateStrategy::saveResult(std::shared_ptr<ResultTable> res, InformationProteinsContainer* data)
{
	res->addRow(new BiResultTableRow(data->getInputConcentration(), data->getChannelConcentration(), data->getOutputConcentration(),
		        error_matrix_->getInputError(), error_matrix_->getOutputError(), information_calculator_->getMutualInformation()));
}

void BivariateStrategy::calculateInformationAndFillTable(std::shared_ptr<ResultTable> res, InformationProteinsContainer* data, bool data_changed)
{
	if(data_changed){
		assignateKD(data);
	}
	initiateSolver(data);
	std::vector<double> upperbounds {data->getChannelConcentration(), data->getInputConcentration(), data->getOutputConcentration(), kd2_, kd1_, kd3_};
	solver_->setUpperBounds(upperbounds);
	solver_->solve();

	calculateMutualInformation(solver_->getSolutions());
	calculateErrorMatrix(solver_->getSolutions());
	saveResult(res, data);
}