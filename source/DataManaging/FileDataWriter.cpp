#include "FileDataWriter.hpp"


void FileDataWriter::setFilename(std::string filename)
{
	filename_ = filename;
}

void FileDataWriter::writeSeparator(std::ofstream* file)
{
	std::string line;
	line.push_back(SPACER);
	line.push_back(DELIMITER);
	std::string subline(PLOTWIDTH, '-');
	for (int i = 0; i < nbData_; i++)
	{
		line.append(subline);
		line.push_back(DELIMITER);
	}
	*file << line << std::endl;
}

void FileDataWriter::writeHeader(std::ofstream* file)
{
	std::string line;
	std::vector<std::string> words = {"Proteins complexes", "Binding partner", "Dissociation Constant (in microM)"};
	int nchars_before = 0;
	int nchars_after = 0;
	int emptychars = 0;

	line.push_back(NDATASYMBOL);
	line.append(" Created on ");
	std::time_t t = std::time(0);
	struct tm* now = localtime(&t);

	line.append(std::to_string(now->tm_mday) + "/" + std::to_string(now->tm_mon+1) + "/" + std::to_string(now->tm_year+1900) + ".");
	*file << line << std::endl;
	*file << NDATASYMBOL;
	*file << " Proteins data for mututal information processing." << std::endl;
	*file << NDATASYMBOL << std::endl << NDATASYMBOL << std::endl;
	*file << NDATASYMBOL << SPACER << "Number of complexes: " + std::to_string(nbData_) << std::endl;
	*file << SPACER << DELIMITER;
	
	for (int i = 0; i < nbData_; i++)
	{
		emptychars = PLOTWIDTH-(words[i].size());
		nchars_before = emptychars/2;
		nchars_after = emptychars/2 + emptychars%2;
		std::string bline(nchars_before, SPACER);
		std::string aline(nchars_after, SPACER);
		*file << bline + words[i] + aline + DELIMITER;
	}
	*file << std::endl;

	writeSeparator(file);
}

std::vector<std::string> FileDataWriter::getWordsInLine(int pos)
{
	std::vector<std::string> words = {complexes_[pos], partners_[pos], dissociation_constants_[pos]};

	return words;
}

std::string FileDataWriter::formatData(int pos)
{
	std::vector<std::string> words = getWordsInLine(pos);
	std::string line;
	line.push_back(SPACER);
	line.push_back(DELIMITER);
	int nchars_before = 0;
	int nchars_after = 0;
	int emptychars = 0;

	for (int i = 0; i < nbData_; i++)
	{
		emptychars = PLOTWIDTH-(words[i].size());
		nchars_before = emptychars/2;
		nchars_after = emptychars/2 + emptychars%2;
		std::string bline(nchars_before, SPACER);
		std::string aline(nchars_after, SPACER);
		line.append(bline + words[i] + aline + DELIMITER);
	}
	return line;
}

bool FileDataWriter::writeData()
{
	std::ofstream file(filename_);
	if (file.is_open())
	{
		writeHeader(&file);
		for (unsigned int i; i < complexes_.size(); i++)
		{
			file << formatData(i) << std::endl;
			writeSeparator(&file);
		}

		file.close();
		return true;
	}
	else
	{
		return false;
	}
}