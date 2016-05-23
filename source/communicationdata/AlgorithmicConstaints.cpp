#include "AlgorithmicConstraints.hpp"

AlgorithmicConstraints::AlgorithmicConstraints(): input_(std::make_shared<ProteinConstraints>()), channel_(std::make_shared<ProteinConstraints>()), output_(std::make_shared<ProteinConstraints>()), inputs_(), type(-1) {}

std::shared_ptr<AlgorithmicConstraints::ProteinConstraints> AlgorithmicConstraints::getInput() const
{
	return input_;
}

std::shared_ptr<AlgorithmicConstraints::ProteinConstraints> AlgorithmicConstraints::getOutput() const
{
	return output_;
}

std::shared_ptr<AlgorithmicConstraints::ProteinConstraints> AlgorithmicConstraints::getChannel() const
{
	return channel_;
}

std::shared_ptr<AlgorithmicConstraints::ProteinConstraints> AlgorithmicConstraints::getInput(int index) const
{
	return inputs_.at(index);
}

int AlgorithmicConstraints::getMutualInformationType() const
{
	return type_;
}

unsigned int AlgorithmicConstraints::getNbInputs() const
{
	return inputs_.size();
}

unsigned int AlgorithmicConstraints::getMaxComplexSize() const
{
	return getNbInputs()+1;
}

void AlgorithmicConstraints::setProteinConstraints(std::shared_ptr<AlgorithmicConstraints::ProteinConstraints> attr, std::shared_ptr<Protein> protein, float init, float final, float step)
{
	attr->protein_ = protein;
	attr->initial_value_ = init;
	attr->final_value_ = final;
	attr->step_ = step;
}

void AlgorithmicConstraints::addInput(std::shared_ptr<Protein> protein, float init, float final, float step)
{
	std::shared_ptr<ProteinConstraints> protconst = std::make_shared<ProteinConstraints>();
	setProteinConstraints(protconst, init, final, step);
	inputs_.push_back(protconst);
}

void AlgorithmicConstraints::resetInputs()
{
	inputs_.clear();
}

void AlgorithmicConstraints::setInput(std::shared_ptr<Protein> protein, float init, float final, float step)
{
	setProteinConstraints(input_, protein, init, final, step);
}

void AlgorithmicConstraints::setOutput(std::shared_ptr<Protein> protein, float init, float final, float step)
{
	setProteinConstraints(output_, protein, init, final, step);
}

void AlgorithmicConstraints::setChannel(std::shared_ptr<Protein> protein, float init, float final, float step)
{
	setProteinConstraints(channel_, protein, init, final, step);
}

void AlgorithmicConstraints::setMutualInformationType(int type)
{
	type_ = type;
}

std::ostream& operator<<( std::ostream &flux, AlgorithmicConstraints const& constraints)
{
	for (unsigned int i = 0; i < constraints.getNbInputs(); i++){
		flux << "Inputs: " << *constraints.getInput(i) << ",";
	}
	flux << std::endl;
	
	flux << "Input: " << *constraints.getInput() << std::endl;
	flux << "Channel: " << *constraints.getChannel() << std::endl;
	flux << "Output: " << *constraints.getOutput() << std::endl;
	return flux;
}

std::ostream& operator<<( std::ostream &flux, AlgorithmicConstraints::ProteinConstraints const& constraints)
{
	flux << constraints.getProtein()->getProteinName() <<",";
	flux << constraints.getInitialValue() << ",";
	flux << constraints.getFinalValue() << ",";
	flux << constraints.getStep();
}