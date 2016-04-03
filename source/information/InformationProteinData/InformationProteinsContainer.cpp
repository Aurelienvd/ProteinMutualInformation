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