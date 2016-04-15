#include "IOManager.hpp"

IOManager::IOManager(ProcessDirector* director): Facade(director), manager_(new InputDataManager()) {}

IOManager::~IOManager()
{
	delete manager_;
}

void IOManager::updateData(ConcreteStream* streamData) const
{
	manager_->updateData(streamData->getComplexes(), streamData->getPartners(), streamData->getConstants());
	manager_->setFilename(streamData->getFilename());
}

bool IOManager::saveData() const
{
	return manager_->writeData();
}

bool IOManager::loadData()
{
	bool success =  manager_->readData();
	jobDone();
	return success;
}

void IOManager::jobDone()
{
	Facade::jobDone();
}

ConcreteStream* IOManager::getData() const
{
	ConcreteStream* stream = new ConcreteStream();

	stream->updateData(manager_->getComplexes(), manager_->getPartners(), manager_->getConstants());
	
	return stream;
}