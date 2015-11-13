#include "DataManager.hpp"


std::vector<std::string> DataManager::getComplexes() const
{
	return complexes_;
}

std::vector<std::string> DataManager::getPartners() const
{
	return partners_;
}

std::vector<double> DataManager::getConstants() const
{
	return dissociation_constants_;
}

unsigned int DataManager::getIndex() const
{
	return index_;
}