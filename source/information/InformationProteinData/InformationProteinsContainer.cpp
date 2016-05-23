#include "InformationProteinsContainer.hpp"
#include <iostream>


InformationProteinsContainer::InformationProteinsContainer(): input_(nullptr), output_(nullptr), channel_(nullptr), inputs_() {}

std::shared_ptr<InformationEntity> InformationProteinsContainer::getInput() const
{
	return input_;
}

std::shared_ptr<InformationEntity> InformationProteinsContainer::getOutput() const
{
	return output_;
}

std::shared_ptr<InformationEntity> InformationProteinsContainer::getChannel() const
{
	return channel_;
}

InformationProteinsContainer::infovector InformationProteinsContainer::getInputs() const
{
	return inputs_;
}

double InformationProteinsContainer::getInputConcentration() const
{
	return input_->getProteinConcentration();
}

double InformationProteinsContainer::getOutputConcentration() const
{
	return output_->getProteinConcentration();
}

double InformationProteinsContainer::getChannelConcentration() const
{
	return channel_->getProteinConcentration();
}

std::vector<double> InformationProteinsContainer::getInputsConcentration() const
{
	std::vector<double> concents;
	for (std::shared_ptr<InformationEntity> entity: inputs_){
		concents.push_back(entity->getProteinConcentration());
	}
	return concents;
}

std::vector<double> InformationProteinsContainer::getInputRange() const
{
	return input_->getRange();
}

std::vector<double> InformationProteinsContainer::getOutputRange() const
{
	return output_->getRange();
}

std::vector<double> InformationProteinsContainer::getChannelRange() const
{
	return channel_->getRange();
}

std::vector<std::vector<double>> InformationProteinsContainer::getInputsRange() const
{
	std::vector<std::vector<double>> ranges;
	for (std::shared_ptr<InformationEntity> entity: inputs_){
		ranges.push_back(entity->getRange());
	}

	return ranges;
}

float InformationProteinsContainer::getBiggestMidRangeValue() const
{
	float max = std::max(input_->getRangeMidValue(), channel_->getRangeMidValue());
	max = std::max(max, output_->getRangeMidValue());
	return max;
}

void InformationProteinsContainer::setInput(std::shared_ptr<InformationEntity> in)
{
	input_.reset();
	input_ = in;
}

void InformationProteinsContainer::setOutput(std::shared_ptr<InformationEntity> out)
{
	output_.reset();
	output_ = out;
}

void InformationProteinsContainer::setChannel(std::shared_ptr<InformationEntity> chan)
{
	channel_.reset();
	channel_ = chan;
}

void InformationProteinsContainer::setInputs(infovector inputs)
{
	inputs_ = inputs;
}

void InformationProteinsContainer::addToInputs(std::shared_ptr<InformationEntity> in)
{
	inputs_.push_back(in);
}

void InformationProteinsContainer::setInputConcentration(double concent)
{
	input_->setProteinConcentration(concent);
}

void InformationProteinsContainer::setOutputConcentration(double concent)
{
	output_->setProteinConcentration(concent);
}

void InformationProteinsContainer::setChannelConcentration(double concent)
{
	channel_->setProteinConcentration(concent);
}

void InformationProteinsContainer::setInputsConcentration(double concent, int index)
{
	inputs_.at(index)->setProteinConcentration(concent);
}

void InformationProteinsContainer::resetInputs()
{
	inputs_.clear();
}

std::vector<std::shared_ptr<ProteinComplex>> InformationProteinsContainer::getOneSidedComplexes(unsigned int size) const
{
	std::vector<std::shared_ptr<ProteinComplex>> res;
	for (std::shared_ptr<ProteinComplex> complex: channel_->getRelatedComplexes()){
		if (complex->getComplexSize() == size){
			res.push_back(complex);
		}
	}
	
	return res;
}

std::shared_ptr<ProteinComplex> InformationProteinsContainer::getWholeCommunicationComplex(unsigned int size) const
{
	for (std::shared_ptr<ProteinComplex> complex: channel_->getRelatedComplexes()){
		if (complex->getComplexSize() == size){
			return complex;
		}
	}
}

std::vector<double> InformationProteinsContainer::getOneSidedComplexesDissociationConstant(unsigned int size) const
{
	std::vector<double> res;
	for (std::shared_ptr<ProteinComplex> complex: getOneSidedComplexes(size)){
		res.push_back(complex->getDissociationConstant());
	}
	return res;
}


double InformationProteinsContainer::getWholeCommunicationComplexDissociationConstant(unsigned int size) const
{
	return getWholeCommunicationComplex(size)->getDissociationConstant();
}

InformationProteinsContainer::complexes_map InformationProteinsContainer::getAllComplexesBetween(unsigned int min, unsigned int max)
{
	complexes_map map;
	for (unsigned int i = min; i < max; i++){
		map.insert(complexes_pair(i, getOneSidedComplexes(i)));
	}
	return map;
}