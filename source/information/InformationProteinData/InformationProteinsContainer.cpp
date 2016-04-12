#include "InformationProteinsContainer.hpp"


InformationProteinsContainer::InformationProteinsContainer(): input_(nullptr), output_(nullptr), channel_(nullptr) {}

InformationProteinsContainer::~InformationProteinsContainer()
{
	delete input_;
	delete output_;
	delete channel_;
}

InformationEntity* InformationProteinsContainer::getInput() const
{
	return input_;
}

InformationEntity* InformationProteinsContainer::getOutput() const
{
	return output_;
}

InformationEntity* InformationProteinsContainer::getChannel() const
{
	return channel_;
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

float InformationProteinsContainer::getBiggestMidRangeValue() const
{
	float max = std::max(input_->getRangeMidValue(), channel_->getRangeMidValue());
	max = std::max(max, output_->getRangeMidValue());
	return max;
}

void InformationProteinsContainer::setInput(InformationEntity* in)
{
	input_ = in;
}

void InformationProteinsContainer::setOutput(InformationEntity* out)
{
	output_ = out;
}

void InformationProteinsContainer::setChannel(InformationEntity* chan)
{
	channel_ = chan;
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

std::vector<ProteinComplex*> InformationProteinsContainer::getOneSidedComplexes(unsigned int size) const
{
	std::vector<ProteinComplex*> res;
	for (ProteinComplex* complex: channel_->getRelatedComplexes()){
		if (complex->getComplexSize() == size){
			res.push_back(complex);
		}
	}
	return res;
}

ProteinComplex* InformationProteinsContainer::getWholeCommunicationComplex(unsigned int size) const
{
	for (ProteinComplex* complex: channel_->getRelatedComplexes()){
		if (complex->getComplexSize() == size){
			return complex;
		}
	}
}

std::vector<double> InformationProteinsContainer::getOneSidedComplexesDissociationConstant(unsigned int size) const
{
	std::vector<double> res;
	for (ProteinComplex* complex: getOneSidedComplexes(size)){
		res.push_back(complex->getDissociationConstant());
	}
	return res;
}


double InformationProteinsContainer::getWholeCommunicationComplexDissociationConstant(unsigned int size) const
{
	return getWholeCommunicationComplex(size)->getDissociationConstant();
}