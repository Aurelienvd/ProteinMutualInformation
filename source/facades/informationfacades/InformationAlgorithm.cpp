#include "InformationAlgorithm.hpp"


InformationAlgorithm::InformationAlgorithm(ProcessDirector* director): Facade(director), strategy_(nullptr) {}


void InformationAlgorithm::setStrategy(std::shared_ptr<InformationStrategy> strat)
{
	strategy_.reset();
	strategy_ = strat;
}


void InformationAlgorithm::startAlgorithm(std::shared_ptr<ResultTable> res, InformationProteinsContainer* data)
{
	strategy_->calculateInformationAndFillTable(res, data);
}