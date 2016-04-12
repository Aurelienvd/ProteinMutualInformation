#include "InformationProteinsContainerBuilder.hpp"
#include <iostream>

InformationProteinsContainerBuilder::InformationProteinsContainerBuilder(ProteinsContainer* data, AlgorithmicConstraints* constraints): constraints_(constraints), 
																		data_(data), information_proteins_data_(nullptr), input_(nullptr), output_(nullptr), channel_(nullptr) {}


void InformationProteinsContainerBuilder::buildCommonPart(AlgorithmicConstraints::ProteinConstraints* constraints, InformationEntity* entity)
{
	entity->setEntity(data_->getProtein(constraints->getProtein()));
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
	entity->addRelatedComplex(data_->getComplexForGlobalProtein(entity->getProtein(), entity->getProtein(), data_->getProtein(partner->getProtein())));
}
		
void InformationProteinsContainerBuilder::addWholeCommunicationComplex()
{
	std::vector<std::shared_ptr<Protein>> base {constraints_->getInput()->getProtein(), constraints_->getChannel()->getProtein()};
	std::vector<std::shared_ptr<Protein>> partner {constraints_->getOutput()->getProtein()};

	ProteinComplex* whole_complex = data_->getComplex(base, partner);
	input_->addRelatedComplex(whole_complex);
	output_->addRelatedComplex(whole_complex);
	channel_->addRelatedComplex(whole_complex);
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
	addWholeCommunicationComplex();
	information_proteins_data_->setInput(input_);
	information_proteins_data_->setOutput(output_);
	information_proteins_data_->setChannel(channel_);
}

InformationProteinsContainer* InformationProteinsContainerBuilder::getInformationProteinsData() const
{
	return information_proteins_data_;
}