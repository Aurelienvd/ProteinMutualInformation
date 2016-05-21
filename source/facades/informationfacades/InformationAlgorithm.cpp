#include "InformationAlgorithm.hpp"
#include <iostream>

InformationAlgorithm::InformationAlgorithm(ProcessDirector* director): Facade(director), strategy_(nullptr), data_changed_(false) {}


void InformationAlgorithm::setStrategy(std::shared_ptr<InformationStrategy> strat)
{
	strategy_.reset();
	strategy_ = strat;
}

void InformationAlgorithm::checkData(std::shared_ptr<InformationProteinsContainer> data) const
{	
	auto one_sided_complexes = data->getOneSidedComplexes(infoconfig::kBIOneSidedComplexSize);
	bool data_valid = true; 
	for (unsigned int i = 0; data_valid && i < one_sided_complexes.size(); i++){
		data_valid = !(one_sided_complexes.at(i)->hasProteinInBase(std::make_shared<Protein>(error_indicator::kUnfoundComplexName)));
	}

	if (!data_valid){
		throw MissingInputDataException();
	}
}

void InformationAlgorithm::startAlgorithm(std::shared_ptr<ResultTable> res, std::shared_ptr<InformationProteinsContainer> data)
{
	try{
		checkData(data);
	} catch(MissingInputDataException& except){
		throw;
	}
	
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