#include "InformationCalculator.hpp"

InformationCalculator::InformationCalculator(ProcessDirector* director): Facade(director), computation_director_(new InformationProcessDirector(this)) {}

InformationCalculator::~InformationCalculator()
{
	delete computation_director_;
}

void InformationCalculator::calculateInformation(ProteinsContainer* data, AlgorithmicConstraints* constraints)
{
	computation_director_->startProcess(data, constraints);
	Facade::jobDone();
}

std::shared_ptr<ResultTable> InformationCalculator::getResult() const
{
	return computation_director_->getResult();
}