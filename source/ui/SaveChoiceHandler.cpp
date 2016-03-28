#include "SaveChoiceHandler.hpp"
#include "../utils/StringSplitter.hpp"

SaveChoiceHandler::SaveChoiceHandler(): request_data_(new StreamRequestData()) {}

std::vector<std::string> SaveChoiceHandler::getStringDataVectorFromUser(std::string message) const
{
	std::string inputs;
	std::cout << message << std::endl;
	std::cin >> inputs;
	return splitString(inputs, DELIMITER_);
}

std::vector<std::string> SaveChoiceHandler::getComplexesFromUser() const
{
	std::string message = "Enter the complexes to save (separate two complexes with ';'):";
	return getStringDataVectorFromUser(message);

}

std::vector<std::string> SaveChoiceHandler::getPartnersFromUser() const
{
	std::string message = "Enter the partners to save (separate two partners with ';'):";
	return getStringDataVectorFromUser(message);
}

std::vector<std::string> SaveChoiceHandler::getConstantsFromUser() const
{
	std::string message = "Enter the constants to save (separate two constants with ';'):";
	return getStringDataVectorFromUser(message);
}

std::string SaveChoiceHandler::getFilenameFromUser() const
{
	std::cout << "Enter the name of the file which the data will be saved in:" << std::endl;
	std::string filename;
	std::cin >> filename;
	return filename;
}

void SaveChoiceHandler::saveData() const
{
	std::string filename = getFilenameFromUser();
	std::vector<std::string> complexes = getComplexesFromUser();
	std::vector<std::string> partners = getPartnersFromUser();
	std::vector<std::string> constants = getConstantsFromUser();
	ConcreteStream* stream = new ConcreteStream();
	stream->updateData(complexes, partners, constants);
	stream->setFilename(filename);
	request_data_->setData(stream);
}

void SaveChoiceHandler::handleChoice()
{
	saveData();
}

StreamRequestData* SaveChoiceHandler::getRequestData() const
{
	return request_data_;
}