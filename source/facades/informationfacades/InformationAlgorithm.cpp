#include "InformationAlgorithm.hpp"
#include <iostream>

InformationAlgorithm::InformationAlgorithm(ProcessDirector* director): Facade(director), strategy_(nullptr), data_changed_(false) {}


void InformationAlgorithm::setStrategy(std::shared_ptr<InformationStrategy> strat)
{
	strategy_.reset();
	strategy_ = strat;
}


void InformationAlgorithm::startAlgorithm(std::shared_ptr<ResultTable> res, InformationProteinsContainer* data)
{
	data_changed_ = true;
	int progress = 0;
	int last_progress = 0;
	unsigned int size = (data->getInputRange().size())*(data->getChannelRange().size())*(data->getOutputRange().size());
	std::cout << progress << " %" << std::endl;

	for (double input_value : data->getInputRange()){
		data->setInputConcentration(input_value);
		for (double channel_value: data->getChannelRange()){
			data->setChannelConcentration(channel_value);
			for (double output_value: data->getOutputRange()){
				data->setOutputConcentration(output_value);
				strategy_->calculateInformationAndFillTable(res, data, data_changed_);
				data_changed_ = false;
				++progress;
				if (((progress*100/size)) > last_progress){
					++last_progress;
					std::cout << last_progress << " %" << std::endl;
				}
			}
		}
	}
	Facade::jobDone();
}