#include "FileDataReader.hpp"


void FileDataReader::setFilename(std::string filename)
{
	filename_ = filename;
}

void FileDataReader::readNbData(std::string line)
{
	bool found = false;
	std::size_t i = 0;

	while (!found && i < line.size())
	{
		try
		{
			nbData_ = std::stoul(line, &i);
			found = true;
		} catch (std::invalid_argument e){
			i++;
		}

	}
}

std::vector<std::string> FileDataReader::extractWordsFromLine(std::string line)
{
	std::vector<std::string> words;
	unsigned int end = 0;

	for (unsigned int j = 0; j < line.size(); j++)
	{
		if (line[j] != SPACER && line[j] != DELIMITER)
		{
			end = line.find(SPACER,j);
			words.push_back(line.substr(j, end-j));
			j = end-1;
		}

	}
	return words;
}

void FileDataReader::readDataFromLine(std::string line)
{
	std::vector<std::string> words;

	words = extractWordsFromLine(line);

	if (words.size() == NBCOLUMNS)
	{
		complexes_.push_back(words[0]);
		partners_.push_back(words[1]);
		dissociation_constants_.push_back(words[2]);
	}
	else
	{
		std::cout << "Data Parsing Failure" << std::endl;
	}


}

bool FileDataReader::readDataFromFile()
{
	std::ifstream file(DATADIRECTORY+("/"+filename_));

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			if (line[0] != NDATASYMBOL && line[0] != TABLESEPARATORSYMBOL)
			{
				readDataFromLine(line);
			}
			else if (line.find(NBRCOMPLEXNAME) != std::string::npos)
			{
				readNbData(line);
			}
		}
		file.close();
		return true;

	}
	else
	{
		return false;
	}

}