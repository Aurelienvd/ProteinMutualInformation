#include "InputDataManager.hpp"


InputDataManager::InputDataManager(): file_reader_(new FileDataReader()), file_writer_(new FileDataWriter()) {}

InputDataManager::~InputDataManager()
{
	delete file_reader_;
	delete file_writer_;
}

void InputDataManager::setFilename(std::string filename)
{
	filename_ = filename;
}

bool InputDataManager::writeData()
{
	file_writer_->setFilename(filename_);
	file_writer_->updateData(complexes_, partners_, dissociation_constants_);
	return file_writer_->writeData();
}

bool InputDataManager::readData()
{
	file_reader_->setFilename(filename_);

	bool noerror = file_reader_->readDataFromFile();
	updateData(file_reader_->getComplexes(), file_reader_->getPartners(), file_reader_->getConstants());

	return noerror;
}

