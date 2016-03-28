#include "StringSplitter.hpp"

std::vector<std::string> splitString(std::string str, char separator)
{
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string tok;
	while (getline(ss, tok, separator)) {
		tokens.push_back(tok);
	}

	return tokens;

}

