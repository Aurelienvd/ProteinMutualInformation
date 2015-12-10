#include "DataManager.hpp"


std::vector<std::string> DataManager::getComplexes() const
{
	return complexes_;
}

std::vector<std::string> DataManager::getPartners() const
{
	return partners_;
}

std::vector<std::string> DataManager::getConstants() const
{
	return dissociation_constants_;
}

unsigned int DataManager::getNbData() const
{
	return nbData_;
}

void DataManager::setNbData(unsigned int nbData)
{
	nbData_ = nbData;
}