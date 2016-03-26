#include "ConcreteStream.hpp"

void ConcreteStream::setFilename(std::string filename)
{
	filename_ = filename;
}

std::vector<std::string> ConcreteStream::splitComplex(std::string complex)
{
	std::vector<std::string> tokens;
	std::stringstream ss(complex);
	std::string tok;
	while (getline(ss, tok, PROTEINSEPARATOR)) {
		tokens.push_back(tok);
	}

	return tokens;
}