#include "DataManager.hpp"

DataManager::DataManager(ProcessDirector* director): Facade(director), manager_(new InputDataManager()) {}

DataManager::~DataManager()
{
	delete manager_;
}

void DataManager::updateData(ConcreteStream* streamData) const
{
	manager_->updateData(streamData->getComplexes(), streamData->getPartners(), streamData->getConstants());
	manager_->setFilename(streamData->getFilename());
}

bool DataManager::saveData() const
{
	return manager_->writeData();
}

bool DataManager::loadData()
{
	bool success =  manager_->readData();
	jobDone();
	return success;
}

void DataManager::jobDone()
{
	Facade::jobDone();
}

ConcreteStream* DataManager::getData() const
{
	ConcreteStream* stream = new ConcreteStream();

	stream->updateData(manager_->getComplexes(), manager_->getPartners(), manager_->getConstants());
	
	return stream;
}