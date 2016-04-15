#ifndef __FILEWRITER__HPP
#define __FILEWRITER__HPP

#include <iostream>
#include <fstream>
#include "Stream.hpp"
#include <ctime>
#include <sys/stat.h>

#define PLOTWIDTH 37

/**
 * A FileWriter that will write formatted program data to a file.
 * 
 * This class also format internal data
 */


class FileDataWriter : public Stream
{
	private:

		//---------------------
		// Private data members
		//---------------------
		//
		// filename_
		//		The name of the file where to save data to.

		std::string filename_;

		//--------------------------
		// Private member functions
		//--------------------------
		//
		// writeHeader
		//		Write a formatted header to the file.
		//
		// writeSeprator
		//		write a formatted separator to the file.
		//
		// formatData
		//		Format data.
		//
		// getWordsInLine
		//		Get a vector of words extracted from a line.
		//
		// createDirectory
		//		Create the directory where the saved file will be located in.

		void writeHeader(std::ofstream* file);
		void writeSeparator(std::ofstream* file);
		std::string formatData(int pos);
		std::vector<std::string> getWordsInLine(int pos);
		void createDirectory() const;

	public:

		//----------------
		// I/O method
		//----------------

		/**
		 * Write the data to the file.
		 *
		 * Use setFilename and updateData before using this.
		 *
		 * @return A boolean value indicating if the I/O operation was successful.
		 *
		 * @see Stream#updateData
		 */

		bool writeData();
		void setFilename(std::string filename) override;
};


#endif /*  __FILEWRITER__HPP  */