#include "StartChoiceHandler.hpp"
#include "../utils/StringSplitter.hpp"
#include "../utils/StringToProteinWrapper.hpp"

StartChoiceHandler::StartChoiceHandler(): request_data_(std::make_shared<AlgorithmRequestData>()) {}


int StartChoiceHandler::getInformationTypeFromUser() const
{
	int type;
	std::cout << "Choose mutual information type (1. bivariate, 2. trivariate): ";
	std::cin >> type;
	return type;
}


std::string StartChoiceHandler::getProteinFromUser(std::string fonction) const
{
	std::string protein;
	std::cout << "Enter the protein (or complex) that will be the " + fonction << std::endl;
	std::cin >> protein;
	return protein; 
}


std::string StartChoiceHandler::getRangeFromUser(std::string fonction) const
{
	std::string range;
	std::cout << "Enter the triplet initial value, final value, step for the " + fonction + " (use ',' as a separator)" << std::endl;
	std::cin >> range;
	return range;
}


std::vector<std::string> StartChoiceHandler::splitRange(std::string range) const
{
	return splitString(range, RANGEDELIMITER);
}


void StartChoiceHandler::setInputUserRequirements(std::shared_ptr<AlgorithmicConstraints> data)
{
	std::string protein = getProteinFromUser("input");
	std::vector<std::string> range = splitRange(getRangeFromUser("input"));
	data->setInput(wrapString(protein), std::stof(range[0]), std::stof(range[1]), std::stof(range[2]));
}


void StartChoiceHandler::setOutputUserRequirements(std::shared_ptr<AlgorithmicConstraints> data)
{
	std::string protein = getProteinFromUser("output");
	std::vector<std::string> range = splitRange(getRangeFromUser("output"));
	data->setOutput(wrapString(protein), std::stof(range[0]), std::stof(range[1]), std::stof(range[2]));
}


void StartChoiceHandler::setChannelUserRequirements(std::shared_ptr<AlgorithmicConstraints> data)
{
	std::string protein = getProteinFromUser("channel");
	std::vector<std::string> range = splitRange(getRangeFromUser("channel"));
	data->setChannel(wrapString(protein), std::stof(range[0]), std::stof(range[1]), std::stof(range[2]));
}


void StartChoiceHandler::handleChoice()
{
	std::shared_ptr<AlgorithmicConstraints> data = std::make_shared<AlgorithmicConstraints>();
	data->setMutualInformationType(getInformationTypeFromUser());
	setInputUserRequirements(data);
	setChannelUserRequirements(data);
	setOutputUserRequirements(data);
	request_data_->setData(data);
}

std::shared_ptr<AlgorithmRequestData> StartChoiceHandler::getRequestData() const
{
	return request_data_;
}