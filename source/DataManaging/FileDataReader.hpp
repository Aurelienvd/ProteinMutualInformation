#include "DataManager.hpp"
#include <iostream>
#include <fstream>


class FileDataReader : public DataManager
{
	private:

	std::string path_;

	void readDataFromLine(std::string line);
	std::vector<std::string> extractWordsFromLine(std::string line);

	public:

	bool readDataFromFile();
	void setFilename(std::string path);
};