#include "InformationProcessDirector.hpp"
#include "../facades/InformationCalculator.hpp"

InformationProcessDirector::InformationProcessDirector(InformationCalculator* facade): upper_facade_(facade), protein_data_(nullptr), adt_(nullptr), algorithm_(nullptr), res_(nullptr), res_writter_(new ResultTableWritter)
{
	createColleagues();
	res_ = std::make_shared<ResultTable>();
}

InformationProcessDirector::~InformationProcessDirector() 
{
	delete protein_data_;
	delete algorithm_;
	if (adt_ != nullptr){
		delete adt_;
	}
	delete res_writter_;
}

void InformationProcessDirector::createColleagues()
{
	protein_data_ = new InformationProteinData(this);
	algorithm_ = new InformationAlgorithm(this);
}

void InformationProcessDirector::directDataJobDone()
{
	adt_ = protein_data_->getADT();
	res_.reset();
	res_ = std::make_shared<ResultTable>();

	if (information_type_ == InformationType::bivariate){

		auto strat = std::make_shared<BivariateStrategy>();
		algorithm_->setStrategy(strat);
		
	} else if (information_type_ == InformationType::trivariate) {

		auto strat = std::make_shared<TrivariateStrategy>();
		algorithm_->setStrategy(strat);
	}

	algorithm_->startAlgorithm(res_, adt_);
}

void InformationProcessDirector::saveResultTable() const
{
	res_->setInput(adt_->getInput()->getCoreProtein());
	res_->setChannel(adt_->getChannel()->getCoreProtein());
	res_->setOutput(adt_->getOutput()->getCoreProtein());
	res_writter_->writeResultTable(res_, "test.txt");
}

void InformationProcessDirector::colleagueJobDone(Facade* facade)
{
	if (facade == protein_data_){
		directDataJobDone();
	} else if (facade == algorithm_){
		saveResultTable();
	}
}

void InformationProcessDirector::startProcess(ProteinsContainer* data, AlgorithmicConstraints* constraints)
{
	information_type_ = constraints->getMutualInformationType();
	protein_data_->constructADT(data, constraints);
}