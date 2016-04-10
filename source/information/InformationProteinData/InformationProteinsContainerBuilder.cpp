#include "InformationProteinsContainerBuilder.hpp"

InformationProteinsContainerBuilder::InformationProteinsContainerBuilder(AlgorithmicConstraints* constraints, ProteinsContainer* data): constraints_(constraints), 
																		data_(data), information_proteins_data_(nullptr), input_(nullptr), output_(nullptr), channel_(nullptr) {}


void InformationProteinsContainerBuilder::buildCommonPart(AlgorithmicConstraints::ProteinConstraints* constraints, InformationEntity* entity)
{
	entity->setEntity(data_->getProtein(constraints->getProteinName()));
	entity->setInitialValue(constraints->getInitialValue());
	entity->setFinalValue(constraints->getFinalValue());
	entity->setStep(constraints->getStep());
	addComplexVersionOfEntity(entity);
}


void InformationProteinsContainerBuilder::addComplexVersionOfEntity(InformationEntity* entity)
{
	entity->addRelatedComplex(data_->getComplexForGlobalProtein(entity->getProtein(), entity->getProtein()));
}

void InformationProteinsContainerBuilder::InformationProteinsContainerBuilder::addOneSidedCommunicationComplex(InformationEntity* entity, AlgorithmicConstraints::ProteinConstraints* partner)
{
	entity->addRelatedComplex(data_->getComplexForGlobalProtein(entity->getProtein(), entity->getProtein(), data_->getProtein(partner->getProteinName())));
}
		
void InformationProteinsContainerBuilder::addWholeCommunicationComplex()
{
	
}

void InformationProteinsContainerBuilder::buildInput()
{
	input_ = new InformationEntity();
	buildCommonPart(constraints_->getInput(), input_);
	addOneSidedCommunicationComplex(input_, constraints_->getChannel());
}

void InformationProteinsContainerBuilder::buildOutput()
{
	output_ = new InformationEntity();
	buildCommonPart(constraints_->getOutput(), output_);
	addOneSidedCommunicationComplex(output_, constraints_->getChannel());
}

void InformationProteinsContainerBuilder::buildChannel()
{
	channel_ = new InformationEntity();
	buildCommonPart(constraints_->getChannel(), channel_);
	addOneSidedCommunicationComplex(channel_, constraints_->getInput());
	addOneSidedCommunicationComplex(channel_, constraints_->getOutput());
}

void InformationProteinsContainerBuilder::buildInformationProteinsContainer()
{
	information_proteins_data_ = new InformationProteinsContainer();
	information_proteins_data_->setInput(input_);
	information_proteins_data_->setOutput(output_);
	information_proteins_data_->setChannel(channel_);
}

InformationProteinsContainer* InformationProteinsContainerBuilder::getInformationProteinsData() const
{
	return information_proteins_data_;
}