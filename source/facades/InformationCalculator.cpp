#include "InformationCalculator.hpp"

InformationCalculator::InformationCalculator(ProcessDirector* director): Facade(director), computation_director_(std::unique_ptr<InformationProcessDirector>(new InformationProcessDirector(this))) {}


void InformationCalculator::calculateInformation(std::shared_ptr<ProteinsContainer> data, std::shared_ptr<AlgorithmicConstraints> constraints)
{
	computation_director_->startProcess(data, constraints);
	Facade::jobDone();
}

std::shared_ptr<ResultTable> InformationCalculator::getResult() const
{
	return computation_director_->getResult();
}