#ifndef __INPUT_MANAGER_HPP
#define __INPUT_MANAGER_HPP

#include "FileDataReader.hpp"
#include "FileDataWriter.hpp"


class InputDataManager: public DataManager
{
	private:

	FileDataReader* file_reader_;
	FileDataWriter* file_writer_;

	bool checkComplexes();
	bool checkPartners() const;
	bool checkConstants() const;

	public:

	InputDataManager();
	~InputDataManager();

	void setFilename(std::string filename) override;
	bool checkData();
	void updateData(std::vector<std::string> complexes, std::vector<std::string> partners, std::vector<std::string> constants);
	bool writeData();
	bool readData(std::string filename);

};



#endif  /*  __INPUT_MANAGER_HPP  */