#include "InputDataManager.hpp"


InputDataManager::InputDataManager(): file_reader_(new FileDataReader()), file_writer_(new FileDataWriter()) {}

InputDataManager::~InputDataManager()
{
	delete file_reader_;
	delete file_writer_;
}

void InputDataManager::updateData(std::vector<std::string> complexes, std::vector<std::string> partners, std::vector<std::string> constants)
{
	complexes_ = complexes;
	partners_ = partners;
	dissociation_constants_ = constants;
}

bool InputDataManager::checkComplexes()
{
	nbData_ = complexes_.size();
	return true;
}

bool InputDataManager::checkPartners() const
{
	if (nbData_ == partners_.size())
	{
		return true;
	}

	return false;

}

bool InputDataManager::checkConstants() const
{
	if (nbData_ == dissociation_constants_.size())
	{
		for (unsigned int i = 0; i < nbData_; i++)
		{
			try
			{
				std::stod(dissociation_constants_[i]);
			}catch (std::invalid_argument& e){
				return false;
			}
		}
		return true;
	}
	
	return false;
}

void InputDataManager::setFilename(std::string filename)
{
	file_writer_->setFilename(filename);
}

bool InputDataManager::checkData()
{
	bool valid = checkComplexes() && checkPartners() && checkConstants();
	return valid;
}

bool InputDataManager::writeData()
{
	file_writer_->updateData(complexes_, partners_, dissociation_constants_);
	return file_writer_->writeData();
}

bool InputDataManager::readData(std::string filename)
{
	file_reader_->setFilename(filename);

	bool noerror = file_reader_->readDataFromFile();
	updateData(file_reader_->getComplexes(), file_reader_->getPartners(), file_reader_->getConstants());

	return noerror;
}

