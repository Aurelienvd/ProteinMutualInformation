#include "StreamManager.hpp"


std::vector<std::string> StreamManager::getComplexes() const
{
	return complexes_;
}

std::vector<std::string> StreamManager::getPartners() const
{
	return partners_;
}

std::vector<std::string> StreamManager::getConstants() const
{
	return dissociation_constants_;
}

unsigned int StreamManager::getNbData() const
{
	return nbData_;
}

void StreamManager::setNbData(unsigned int nbData)
{
	nbData_ = nbData;
}