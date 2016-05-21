#include "Stream.hpp"

Stream::Stream(): complexes_(), partners_(), dissociation_constants_() {}

std::vector<std::string> Stream::getComplexes() const
{
	return complexes_;
}

std::vector<std::string> Stream::getPartners() const
{
	return partners_;
}

std::vector<std::string> Stream::getConstants() const
{
	return dissociation_constants_;
}

unsigned int Stream::getNbData() const
{
	return nbData_;
}

void Stream::updateData(std::vector<std::string> complexes, std::vector<std::string> partners, std::vector<std::string> constants)
{
	complexes_ = complexes;
	partners_ = partners;
	dissociation_constants_ = constants;
	nbData_ = complexes.size();
}