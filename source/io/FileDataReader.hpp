
/**
 * A FileReader that will get the data from a file which filename was given before.
 */

#ifndef __FILEREADER__HPP
#define __FILEREADER__HPP

#include "Stream.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>



class FileDataReader : public Stream
{
	private:

		//--------------------------
		// Private data members
		//--------------------------
		//
		// filename_
		//		The name of the file where read data from.

		//--------------------------
		// Private member functions
		//-------------------------
		//
		// readDataFromLine
		// 		Read Data from a line given as param.
		//
		// extractWordsFromLine
		//		Split a line in a vector of words.
		//
		// readNbData
		//		Read the number of data in the file.

		std::string filename_;

		void readDataFromLine(std::string line);
		std::vector<std::string> extractWordsFromLine(std::string line);
		void readNbData(std::string line);

	public:

		//----------------------
		// I/O method
		//----------------------

		/**
		 * Read the data from a correctly formatted file.
		 *
		 * @return A boolean value indicating if the I/O operation was successful.
		 *
		 * @see FileDataWriter
		 */

		bool readDataFromFile();

		/**
		 * Set the filename where load data from.
		 *
		 * @param The filename.
		 */

		void setFilename(std::string filename) override;
};

#endif /*  __FILEREADER__HPP */