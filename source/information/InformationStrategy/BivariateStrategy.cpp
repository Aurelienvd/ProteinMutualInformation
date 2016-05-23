#include "BivariateStrategy.hpp"


BivariateStrategy::BivariateStrategy(): error_matrix_(std::unique_ptr<MatrixCalculator>(new MatrixCalculator())), solver_(std::unique_ptr<InformationRootFinder>(new InformationRootFinder())), 
										information_calculator_(std::unique_ptr<BiInformationCalculator>(new BiInformationCalculator())), 
										octave_solver_(std::unique_ptr<OctaveRootFinder>(new OctaveRootFinder())), kd1_(0), kd2_(0), kd3_(0), gsl_diverged_(false) {}



void BivariateStrategy::assignateKD(std::shared_ptr<InformationProteinsContainer> data)
{
	std::vector<double> one_sided_kds = data->getOneSidedComplexesDissociationConstant(infoconfig::kBIOneSidedComplexSize);
	kd1_ = one_sided_kds.at(0);
	kd2_ = one_sided_kds.at(1);
	kd3_ = data->getWholeCommunicationComplexDissociationConstant(infoconfig::kBIWholeComplexSize);
}

void BivariateStrategy::calculateMutualInformation(std::vector<double> concentrations)
{	
	information_calculator_->setConcentrations(concentrations);
	information_calculator_->calculateMutualInformation();
}

void BivariateStrategy::initiateOctaveSolver(std::shared_ptr<InformationProteinsContainer> data, std::vector<double> bounds)
{
	std::vector<double> values {data->getChannelConcentration(), data->getInputConcentration(), data->getOutputConcentration(), kd2_, kd1_, kd3_};
	octave_solver_->setValues(values);
	octave_solver_->setUpperBounds(bounds);
}

void BivariateStrategy::initiateSolver(std::shared_ptr<InformationProteinsContainer> data)
{
	solver_->initiateFunction(data->getChannelConcentration(), data->getInputConcentration(), data->getOutputConcentration(), kd2_, kd1_, kd3_);
}

void BivariateStrategy::calculateErrorMatrix(std::vector<double> concentrations)
{
	error_matrix_->calculateError(concentrations);
}

void BivariateStrategy::displayProgressMsg(const std::string& msg) const
{
	std::cout << std::endl << msg << std ::endl;
	std::cout << error_indications::kGSLDivergenceIndications << std::endl << std::endl;
	std::cout << progress::kSolveWithOctave << std::endl << std::endl;
}

void BivariateStrategy::saveResult(std::shared_ptr<ResultTable> res, std::shared_ptr<InformationProteinsContainer> data)
{
	res->addRow(std::make_shared<BiResultTableRow>(data->getInputConcentration(), data->getChannelConcentration(), data->getOutputConcentration(),
		        error_matrix_->getInputError(), error_matrix_->getOutputError(), information_calculator_->getMutualInformation()));
}

void BivariateStrategy::calculateInformationAndFillTable(std::shared_ptr<ResultTable> res, std::shared_ptr<InformationProteinsContainer> data, bool data_changed)
{
	if(data_changed){
		assignateKD(data);
	}
	
	std::vector<double> upperbounds {data->getChannelConcentration(), data->getInputConcentration(), data->getOutputConcentration(), kd2_, kd1_, kd3_};
	std::vector<double> solutions;
	solver_->setUpperBounds(upperbounds);
	if (!gsl_diverged_){
		try{
			initiateSolver(data);
			solver_->solve();
			solutions = solver_->getSolutions();
		} catch (GSLDivergenceException& except){
			displayProgressMsg(except.what());
			gsl_diverged_ = true;
			initiateOctaveSolver(data, upperbounds);
			octave_solver_->solve();
			solutions = octave_solver_->getSolutions();
		}
	} else {
		initiateOctaveSolver(data, upperbounds);
		octave_solver_->solve();
		solutions = octave_solver_->getSolutions();
	}
	

	calculateMutualInformation(solutions);
	calculateErrorMatrix(solutions);
	saveResult(res, data);
}