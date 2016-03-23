#include "DataManager.hpp"

DataManager::DataManager(): manager_(new InputDataManager()) {}

DataManager::~DataManager()
{
	delete manager_;
}

void DataManager::updateData(ConcreteStream& streamData) const
{
	manager_->updateData(streamData.getComplexes(), streamData.getPartners(), streamData.getConstants());
}

bool DataManager::saveData(std::string filename) const
{
	manager_->setFilename(filename);
	return manager_->writeData();
}

ConcreteStream* DataManager::loadData(std::string filename) const
{
	manager_->setFilename(filename);
	bool success = manager_->readData();
	ConcreteStream* stream = new ConcreteStream();
	
	if (success){

		stream->updateData(manager_->getComplexes(), manager_->getPartners(), manager_->getConstants());
	}
	
	return stream;
}