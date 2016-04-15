#include "BivariateStrategy.hpp"


BivariateStrategy::BivariateStrategy(): error_matrix_(new MatrixCalculator()), solver_(new RootFinder()), information_calculator_(new BiInformationCalculator()), 
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
	solver_->initiateFunction(data->getChannelConcentration(), data->getInputConcentration(), data->getOutputConcentration(), kd2_, kd1_, kd3_);
}

void BivariateStrategy::calculateInformationAndFillTable(std::shared_ptr<ResultTable> res, InformationProteinsContainer* data, bool data_changed)
{
	if(data_changed){
		assignateKD(data);
	}
	initiateSolver(data);
	double init = data->getBiggestMidRangeValue();
	solver_->solveSystem(std::min(init, data->getChannelConcentration()),std::min(init, data->getInputConcentration()), std::min(init, data->getOutputConcentration()),
	 		 std::min(init, kd2_), std::min(init, kd1_), std::min(init, kd3_));

	calculateMutualInformation(solver_->getSolutions());
}