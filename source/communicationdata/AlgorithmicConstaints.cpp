#include "AlgorithmicConstraints.hpp"

AlgorithmicConstraints::AlgorithmicConstraints(): input_(nullptr), output_(nullptr), channel_(nullptr) {}

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

void AlgorithmicConstraints::setProteinConstraints(AlgorithmicConstraints::ProteinConstraints* attr, GlobalProtein* protein, int init, int final, float step)
{
	attr->protein_ = protein;
	attr->initial_value_ = init;
	attr->final_value_ = final;
	attr->step_ = step;
}

void AlgorithmicConstraints::setInput(GlobalProtein* protein, int init, int final, float step)
{
	setProteinConstraints(input_, protein, init, final, step);
}

void AlgorithmicConstraints::setOutput(GlobalProtein* protein, int init, int final, float step)
{
	setProteinConstraints(output_, protein, init, final, step);
}

void AlgorithmicConstraints::setChannel(GlobalProtein* protein, int init, int final, float step)
{
	setProteinConstraints(channel_, protein, init, final, step);
}

void AlgorithmicConstraints::setMutualInformationType(int type)
{
	type_ = type;
}