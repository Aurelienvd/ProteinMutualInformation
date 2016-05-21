#include "InformationProteinData.hpp"


InformationProteinData::InformationProteinData(ProcessDirector* director): Facade(director), adt_builder_(nullptr) {}


void InformationProteinData::constructADT(std::shared_ptr<ProteinsContainer> data, std::shared_ptr<AlgorithmicConstraints> constraints)
{
	adt_builder_ = std::unique_ptr<InformationProteinsContainerBuilder>(new InformationProteinsContainerBuilder(data, constraints));
	adt_builder_->buildInput();
	adt_builder_->buildChannel();
	adt_builder_->buildOutput();
	adt_builder_->buildInformationProteinsContainer();
	Facade::jobDone();
}


std::shared_ptr<InformationProteinsContainer> InformationProteinData::getADT() const
{
	return adt_builder_->getInformationProteinsData();
}