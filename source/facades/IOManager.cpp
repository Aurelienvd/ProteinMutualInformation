#include "IOManager.hpp"

IOManager::IOManager(ProcessDirector* director): Facade(director), manager_(std::unique_ptr<InputDataManager>(new InputDataManager())) {}


void IOManager::updateData(std::shared_ptr<ConcreteStream> streamData) const
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

std::shared_ptr<ConcreteStream> IOManager::getData() const
{
	auto stream = std::make_shared<ConcreteStream>(); 

	stream->updateData(manager_->getComplexes(), manager_->getPartners(), manager_->getConstants());
	
	return stream;
}