#include "ProteinData.hpp"

ProteinData::ProteinData(ProcessDirector* director): Facade(director), protein_adt_builder_(std::unique_ptr<ProteinsContainerBuilder>(new ProteinsContainerBuilder())) {}

void ProteinData::constructADT(std::shared_ptr<ConcreteStream> data)
{
	protein_adt_builder_->updateData(data);
	protein_adt_builder_->buildGlobalProtein();
	protein_adt_builder_->buildProteinComplexes();
	protein_adt_builder_->buildProteinsContainer();
	Facade::jobDone();
}

std::shared_ptr<ProteinsContainer> ProteinData::getADT() const
{
	return protein_adt_builder_->getProteinsContainer();
}