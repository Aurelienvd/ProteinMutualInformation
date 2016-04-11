#include "InformationProcessDirector.hpp"
#include "../facades/InformationCalculator.hpp"

InformationProcessDirector::InformationProcessDirector(InformationCalculator* facade): upper_facade_(facade), protein_data_(nullptr), adt_(nullptr)
{
	createColleagues();
}

InformationProcessDirector::~InformationProcessDirector() 
{
	delete protein_data_;
	if (adt_ != nullptr){
		delete adt_;
	}
}

void InformationProcessDirector::createColleagues()
{
	protein_data_ = new InformationProteinData(this);
}

void InformationProcessDirector::colleagueJobDone(Facade* facade)
{
	if (facade == protein_data_){
		adt_ = protein_data_->getADT();
	}
}

void InformationProcessDirector::startProcess(ProteinsContainer* data, AlgorithmicConstraints* constraints)
{
	protein_data_->constructADT(data, constraints);
}