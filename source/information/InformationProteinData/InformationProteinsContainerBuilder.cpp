#include "InformationProteinsContainerBuilder.hpp"
#include <iostream>

InformationProteinsContainerBuilder::InformationProteinsContainerBuilder(std::shared_ptr<ProteinsContainer> data, std::shared_ptr<AlgorithmicConstraints> constraints): data_(data), constraints_(constraints), 
																		information_proteins_data_(nullptr), input_(nullptr), output_(nullptr), channel_(nullptr), inputs_() {}


void InformationProteinsContainerBuilder::buildCommonPart(std::shared_ptr<AlgorithmicConstraints::ProteinConstraints> constraints, std::shared_ptr<InformationEntity> entity)
{
	entity->setEntity(data_->getProtein(constraints->getProtein()));
	entity->setInitialValue(constraints->getInitialValue());
	entity->setFinalValue(constraints->getFinalValue());
	entity->setStep(constraints->getStep());
	addComplexVersionOfEntity(entity);
}

void InformationProteinsContainerBuilder::addComplexVersionOfEntity(std::shared_ptr<InformationEntity> entity)
{
	entity->addRelatedComplex(data_->getComplexForGlobalProtein(entity->getProtein(), entity->getProtein()));
}

void InformationProteinsContainerBuilder::InformationProteinsContainerBuilder::addOneSidedCommunicationComplex(std::shared_ptr<InformationEntity> entity, std::shared_ptr<AlgorithmicConstraints::ProteinConstraints> partner)
{
	entity->addRelatedComplex(data_->getComplexForGlobalProtein(entity->getProtein(), entity->getProtein(), data_->getProtein(partner->getProtein())));
}

void InformationProteinsContainerBuilder::addAllCommunicationComplexes(std::shared_ptr<InformationEntity> entity, unsigned int min, unsigned int max)
{
	entity->setRelatedComplexes(data_->getComplexesForGlobalProtein(entity->getProtein(), min, max));
}

void InformationProteinsContainerBuilder::addWholeCommunicationComplex()
{
	std::vector<std::shared_ptr<Protein>> base {constraints_->getInput()->getProtein(), constraints_->getChannel()->getProtein()};
	std::vector<std::shared_ptr<Protein>> partner {constraints_->getOutput()->getProtein()};

	std::shared_ptr<ProteinComplex> whole_complex = data_->getComplex(base, partner);
	input_->addRelatedComplex(whole_complex);
	output_->addRelatedComplex(whole_complex);
	channel_->addRelatedComplex(whole_complex);
}

void InformationProteinsContainerBuilder::buildInputs()
{
	unsigned int nb_inputs = constraints_->getNbInputs();

	for (unsigned int i = 0; i < nb_inputs; i++){
		std::shared_ptr<InformationEntity> input = std::make_shared<InformationEntity>();
		buildCommonPart(constraints_->getInput(i), input);
		addAllCommunicationComplexes(input, protein::kMinComplexSize, constraints_->getMaxComplexSize());
		inputs_.push_back(input);
	}
}

void InformationProteinsContainerBuilder::buildInput()
{
	input_ = std::make_shared<InformationEntity>();
	buildCommonPart(constraints_->getInput(), input_);
	addOneSidedCommunicationComplex(input_, constraints_->getChannel());
}

void InformationProteinsContainerBuilder::buildOutput()
{
	output_ = std::make_shared<InformationEntity>();
	buildCommonPart(constraints_->getOutput(), output_);
	addOneSidedCommunicationComplex(output_, constraints_->getChannel());
}

void InformationProteinsContainerBuilder::buildChannel()
{
	channel_ = std::make_shared<InformationEntity>();
	buildCommonPart(constraints_->getChannel(), channel_);
	addAllCommunicationComplexes(channel_, protein::kMinComplexSize, constraints_->getMaxComplexSize());
}

void InformationProteinsContainerBuilder::buildInformationProteinsContainer()
{
	information_proteins_data_ = std::make_shared<InformationProteinsContainer>();
	addWholeCommunicationComplex();
	information_proteins_data_->setInput(input_);
	information_proteins_data_->setOutput(output_);
	information_proteins_data_->setChannel(channel_);
}

std::shared_ptr<InformationProteinsContainer> InformationProteinsContainerBuilder::getInformationProteinsData() const
{
	return information_proteins_data_;
}