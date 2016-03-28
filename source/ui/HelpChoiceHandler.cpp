#include "HelpChoiceHandler.hpp"


void HelpChoiceHandler::readFile()
{
	std::ifstream file(HELPTEXT);

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			text_ += line;
		}
		file.close();
	}

}

void HelpChoiceHandler::displayText() const
{
	std::cout << "\n" << std::endl;
	std::cout << text_;
	std::cout << "\n" << std::endl;
}

void HelpChoiceHandler::handleChoice()
{
	readFile();
	displayText();
}