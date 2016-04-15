#include "InformationAlgorithm.hpp"

InformationAlgorithm::InformationAlgorithm(ProcessDirector* director): Facade(director), strategy_(nullptr), data_changed_(false) {}


void InformationAlgorithm::setStrategy(std::shared_ptr<InformationStrategy> strat)
{
	strategy_.reset();
	strategy_ = strat;
}


void InformationAlgorithm::startAlgorithm(std::shared_ptr<ResultTable> res, InformationProteinsContainer* data)
{
	data_changed_ = true;

	for (double input_value : data->getInputRange()){
		data->setInputConcentration(input_value);
		for (double channel_value: data->getChannelRange()){
			data->setChannelConcentration(channel_value);
			for (double output_value: data->getOutputRange()){
				data->setOutputConcentration(output_value);
				strategy_->calculateInformationAndFillTable(res, data, data_changed_);
				data_changed_ = false;
			}
		}
	}
}