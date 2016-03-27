#ifndef __INPUT_MANAGER_HPP
#define __INPUT_MANAGER_HPP

#include "FileDataReader.hpp"
#include "FileDataWriter.hpp"


class InputDataManager: public Stream
{
	private:

	FileDataReader* file_reader_;
	FileDataWriter* file_writer_;
	std::string filename_;

	public:

	InputDataManager();
	~InputDataManager();

	void setFilename(std::string filename) override;
	bool writeData();
	bool readData();

};



#endif  /*  __INPUT_MANAGER_HPP  */