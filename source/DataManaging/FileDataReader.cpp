#include "FileDataReader.hpp"


void FileDataReader::setFilename(std::string path)
{
	path_ = path;
}

std::vector<std::string> FileDataReader::extractWordsFromLine(std::string line)
{
	std::vector<std::string> words;
	for (int i = 0; i < NBDATA; i++)
	{
		unsigned int end = 0;
		for (unsigned int j = end; j < line.size(); j++)
		{
			if (line[j] != SPACER && line[j] != DELIMITER)
			{
				end = line.find(SPACER,j);
				words.push_back(line.substr(j, end-j));
			}

		}
	}
	return words;
}

void FileDataReader::readDataFromLine(std::string line)
{
	std::vector<std::string> words;

	words = extractWordsFromLine(line);

	if (words.size() == NBDATA)
	{
		complexes_.push_back(words[0]);
		partners_.push_back(words[1]);
		dissociation_constants_.push_back(std::stod(words[2]));
	}
	else
	{
		std::cout << "Data Parsing Failure" << std::endl;
	}


}

bool FileDataReader::readDataFromFile()
{
	std::ifstream file(path_, std::ios::in);

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			readDataFromLine(line);
		}
		return true;

	}
	else
	{
		return false;
	}

}