#include "InformationCalculator.hpp"

InformationCalculator::InformationCalculator(ProcessDirector* director): Facade(director), computation_director_(new InformationProcessDirector(this)) {}

InformationCalculator::~InformationCalculator()
{
	delete director_;
}