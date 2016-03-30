#include "ProteinData.hpp"

ProteinData::ProteinData(ProcessDirector* director): Facade(director), protein_adt_builder_(new ProteinsContainerBuilder()) {}

ProteinData::~ProteinData()
{
	delete protein_adt_builder_;
}

void ProteinData::constructADT(ConcreteStream* data)
{
	protein_adt_builder_->updateData(data);
	protein_adt_builder_->buildGlobalProtein();
	protein_adt_builder_->buildProteinComplexes();
	protein_adt_builder_->buildProteinsContainer();
}

ProteinsContainer* ProteinData::getADT() const
{
	return protein_adt_builder_->getProteinsContainer();
}