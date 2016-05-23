#include "InformationProcessDirector.hpp"
#include "../facades/InformationCalculator.hpp"

InformationProcessDirector::InformationProcessDirector(InformationCalculator* facade): upper_facade_(facade), protein_data_(nullptr), algorithm_(nullptr), adt_(nullptr), res_(nullptr), res_writter_(nullptr)
{
	createColleagues();
	res_ = std::make_shared<ResultTable>();
	res_writter_ = std::unique_ptr<ResultTableWritter>(new ResultTableWritter());
}

InformationProcessDirector::~InformationProcessDirector() 
{
	delete protein_data_;
	delete algorithm_;
}

void InformationProcessDirector::createColleagues()
{
	protein_data_ = new InformationProteinData(this);
	algorithm_ = new InformationAlgorithm(this);
}

std::shared_ptr<ResultTable> InformationProcessDirector::getResult() const
{
	return res_;
}

void InformationProcessDirector::directDataJobDone()
{
	adt_ = protein_data_->getADT();
	res_.reset();
	res_ = std::make_shared<ResultTable>();

	if (information_type_ == protein::kInformationType::bivariate){

		auto strat = std::make_shared<BivariateStrategy>();
		algorithm_->setStrategy(strat);
		
	} else if (information_type_ == protein::kInformationType::trivariate) {

		auto strat = std::make_shared<TrivariateStrategy>();
		algorithm_->setStrategy(strat);
	}

	try{
		algorithm_->startAlgorithm(res_, adt_);
	} catch (MissingInputDataException& except){
		std::cout << std::endl << "Exception Raised: ";
		std::cout << except.what() << std::endl;
		std::cout << error_indications::kMissingInputDataIndications << std::endl;
	}
}

void InformationProcessDirector::saveResultTable() const
{
	res_->setInput(adt_->getInput()->getCoreProtein());
	res_->setChannel(adt_->getChannel()->getCoreProtein());
	res_->setOutput(adt_->getOutput()->getCoreProtein());
	res_writter_->writeResultTable(res_, "test.dat");
}

void InformationProcessDirector::colleagueJobDone(Facade* facade)
{
	if (facade == protein_data_){
		directDataJobDone();
	} else if (facade == algorithm_){
		saveResultTable();
	}
}

void InformationProcessDirector::startProcess(std::shared_ptr<ProteinsContainer> data, std::shared_ptr<AlgorithmicConstraints> constraints)
{
	information_type_ = constraints->getMutualInformationType();
	protein_data_->constructADT(data, constraints);
}