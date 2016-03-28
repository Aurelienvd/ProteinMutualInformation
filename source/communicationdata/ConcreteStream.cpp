#include "ConcreteStream.hpp"
#include "../utils/StringSplitter.hpp"

void ConcreteStream::setFilename(std::string filename)
{
	filename_ = filename;
}

std::vector<std::string> ConcreteStream::splitComplex(std::string complex)
{
	return splitString(complex, PROTEINSEPARATOR);
}

std::vector<double> ConcreteStream::getConstantsAsDoubleVector() const
{
	std::vector<double> constants;
	for (std::string c : dissociation_constants_){
		constants.push_back(std::stod(c));
	}
	return constants;
}