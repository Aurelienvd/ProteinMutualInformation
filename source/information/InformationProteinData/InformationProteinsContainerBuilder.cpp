#include "InformationProteinsContainerBuilder.hpp"

InformationProteinsContainerBuilder::InformationProteinsContainerBuilder(AlgorithmicConstraints* constraints, ProteinsContainer* data): constraints_(constraints), 
																		data_(data), information_proteins_data_(nullptr), input_(nullptr), output_(nullptr), channel_(nullptr) {}


void InformationProteinsContainerBuilder::buildInput()
{

}

void InformationProteinsContainerBuilder::buildOutput()
{

}

void InformationProteinsContainerBuilder::buildChannel()
{

}

InformationProteinsContainer* InformationProteinsContainerBuilder::getInformationProteinsData() const
{
	return information_proteins_data_;
}