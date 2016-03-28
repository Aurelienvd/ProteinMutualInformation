#include "LoadChoiceHandler.hpp"

LoadChoiceHandler::LoadChoiceHandler(): request_data_(new StreamRequestData()) {}

void LoadChoiceHandler::handleChoice()
{
	std::cout << "Enter the name of the file to load: ";
	std::string filename;
	std::cin >> filename;
	ConcreteStream* stream = new ConcreteStream();
	stream->setFilename(filename);
	request_data_->setData(stream);
}

StreamRequestData* LoadChoiceHandler::getRequestData() const
{
	return request_data_;
}