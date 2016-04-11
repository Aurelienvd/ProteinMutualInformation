#include "InformationProteinData.hpp"


InformationProteinData::InformationProteinData(ProcessDirector* director): Facade(director), adt_builder_(nullptr) {}

InformationProteinData::~InformationProteinData()
{
	if( adt_builder_ != nullptr){
		delete adt_builder_;
	}
}

void InformationProteinData::constructADT(ProteinsContainer* data, AlgorithmicConstraints* constraints)
{
	adt_builder_ = new InformationProteinsContainerBuilder(data, constraints);
	adt_builder_->buildInput();
	adt_builder_->buildChannel();
	adt_builder_->buildOutput();
	adt_builder_->buildInformationProteinsContainer();
	Facade::jobDone();
}


InformationProteinsContainer* InformationProteinData::getADT() const
{
	return adt_builder_->getInformationProteinsData();
}