#include "AlgorithmicConstraints.hpp"

AlgorithmicConstraints::AlgorithmicConstraints(): input_(new ProteinConstraints), output_(new ProteinConstraints), channel_(new ProteinConstraints) {}

AlgorithmicConstraints::~AlgorithmicConstraints()
{
	delete input_;
	delete output_;
	delete channel_;
}

AlgorithmicConstraints::ProteinConstraints* AlgorithmicConstraints::getInput() const
{
	return input_;
}

AlgorithmicConstraints::ProteinConstraints* AlgorithmicConstraints::getOutput() const
{
	return output_;
}

AlgorithmicConstraints::ProteinConstraints* AlgorithmicConstraints::getChannel() const
{
	return channel_;
}

int AlgorithmicConstraints::getMutualInformationType() const
{
	return type_;
}

void AlgorithmicConstraints::setProteinConstraints(AlgorithmicConstraints::ProteinConstraints* attr, std::shared_ptr<Protein> protein, int init, int final, float step)
{
	attr->protein_ = protein;
	attr->initial_value_ = init;
	attr->final_value_ = final;
	attr->step_ = step;
}

void AlgorithmicConstraints::setInput(std::shared_ptr<Protein> protein, int init, int final, float step)
{
	setProteinConstraints(input_, protein, init, final, step);
}

void AlgorithmicConstraints::setOutput(std::shared_ptr<Protein> protein, int init, int final, float step)
{
	setProteinConstraints(output_, protein, init, final, step);
}

void AlgorithmicConstraints::setChannel(std::shared_ptr<Protein> protein, int init, int final, float step)
{
	setProteinConstraints(channel_, protein, init, final, step);
}

void AlgorithmicConstraints::setMutualInformationType(int type)
{
	type_ = type;
}