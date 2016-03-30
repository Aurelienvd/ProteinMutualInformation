#ifndef __FILEREADER__HPP
#define __FILEREADER__HPP

#include "Stream.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>



class FileDataReader : public Stream
{
	private:

		std::string filename_;

		void readDataFromLine(std::string line);
		std::vector<std::string> extractWordsFromLine(std::string line);
		void readNbData(std::string line);

	public:

		bool readDataFromFile();
		void setFilename(std::string filename) override;
};

#endif /*  __FILEREADER__HPP */