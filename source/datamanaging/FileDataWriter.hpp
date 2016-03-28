#ifndef __FILEWRITER__HPP
#define __FILEWRITER__HPP

#include <iostream>
#include <fstream>
#include "Stream.hpp"
#include <ctime>

#define PLOTWIDTH 37


class FileDataWriter : public Stream
{
	private:

		std::string filename_;

		void writeHeader(std::ofstream* file);
		void writeSeparator(std::ofstream* file);
		std::string formatData(int pos);
		std::vector<std::string> getWordsInLine(int pos);

	public:

		bool writeData();
		void setFilename(std::string filename) override;
};


#endif /*  __FILEWRITER__HPP  */