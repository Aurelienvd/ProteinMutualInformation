#include "LoadChoiceHandler.hpp"

LoadChoiceHandler::LoadChoiceHandler(): request_data_(std::make_shared<StreamRequestData>()) {}

void LoadChoiceHandler::handleChoice()
{
	std::cout << "Enter the name of the file to load: ";
	std::string filename;
	std::cin >> filename;
	auto stream = std::make_shared<ConcreteStream>();
	stream->setFilename(filename);
	request_data_->setData(stream);
}

std::shared_ptr<StreamRequestData> LoadChoiceHandler::getRequestData() const
{
	return request_data_;
}