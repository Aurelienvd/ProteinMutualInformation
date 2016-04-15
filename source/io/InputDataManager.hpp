
/**
 * InputDataManager manages the I/O operations classes.
 *
 * @see FileDataReader
 * @see FileDataWriter
 */

#ifndef __INPUT_MANAGER_HPP
#define __INPUT_MANAGER_HPP

#include "FileDataReader.hpp"
#include "FileDataWriter.hpp"


class InputDataManager: public Stream
{
	private:

	//---------------------------
	// Private data members
	//---------------------------
	//
	// file_reader_
	// 		see FileDataReader
	//
	// file_writer_
	// 		see FileDataWriter
	//
	// filename_
	// 		The name of the file.

	FileDataReader* file_reader_;
	FileDataWriter* file_writer_;
	std::string filename_;

	public:

	InputDataManager();
	~InputDataManager();

	/**
	 * Set the filename.
	 *
	 * @param The name of the file.
	 *
	 * @see Stream#setFilename
	 */

	void setFilename(std::string filename) override;

	/**
	 * Write data to a file.
	 *
	 * @return A boolean value indicating if the I/O operation was successful.
	 *
	 * @see FileDataWriter
	 */

	bool writeData();

	/**
	 * Read data from a file.
	 *
	 * @return A boolean value indicating if the I/O operation was successful.
	 *
	 * @see FileDataReader
	 */

	bool readData();

};



#endif  /*  __INPUT_MANAGER_HPP  */