#ifndef __FILEREADER__HPP
#define __FILEREADER__HPP

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

#endif /*  __FILEREADER__HPP */