#include "MainMenu.hpp"

MainMenu::MainMenu()
{
	addHeader();
	addMenu();

}

void MainMenu::addHeader()
{
	std::string title = "\n\nProtein Information Program";
	menu+= title + '\n';
	menu+= std::string(title.size(), '<') + "\n\n\n";
	menu+= std::string(SPACERSIZE, ' ') + std::string(LINESIZE, DECOYCHAR) + '\n';

}

void MainMenu::addLine(std::string line)
{
	static std::string spacer = std::string(SPACERSIZE, ' ');

	if (line.size() <= LINESIZE-3)
	{
		menu += spacer + DECOYCHAR + ' ' + line + std::string(LINESIZE-line.size()-3, ' ') + DECOYCHAR + '\n';
	}
	else
	{
		menu += spacer + DECOYCHAR + ' ' + line.substr(0, LINESIZE-3) + DECOYCHAR + '\n';
	}

}
void MainMenu::addSeparator()
{
	static std::string spacer = std::string(SPACERSIZE, ' ');

	menu += spacer + DECOYCHAR + ' ' + std::string(LINESIZE-3, ' ') + DECOYCHAR + '\n'; 
}


void MainMenu::addMenu()
{
	std::vector<std::string> lines = {"1. Load data from file", "2. Save data", "3. Start the algorithm", "4. Get Help", "5. Quit"};
	unsigned int size = lines.size();
	int count = 0;
	for (int i = 1; i < MENUSIZE; i++)
	{
		if (count < size && i%2 == 0)
		{
			addLine(lines.at(count));
			count++;
		}
		else
		{
			addSeparator();
		}
	}
	menu+= std::string(SPACERSIZE, ' ') + std::string(LINESIZE, DECOYCHAR) + "\n\n"; 
}

std::vector<std::string> MainMenu::split(std::string str) const
{
	std::vector<std::string> tokens;
	std::stringstream ss(str);
	std::string tok;
	while (getline(ss, tok, DELIMITER)) {
		tokens.push_back(tok);
	}

	return tokens;

}

std::vector<std::string> MainMenu::getStringDataVectorFromUser(std::string message) const
{
	std::string inputs;
	std::cout << message << std::endl;
	std::cin >> inputs;
	return split(inputs);
}

std::vector<std::string> MainMenu::getComplexesFromUser() const
{
	std::string message = "Enter the complexes to save (separate two complexes with ';'):";
	return getStringDataVectorFromUser(message);

}

std::vector<std::string> MainMenu::getPartnersFromUser() const
{
	std::string message = "Enter the partners to save (separate two partners with ';'):";
	return getStringDataVectorFromUser(message);
}

std::vector<std::string> MainMenu::getConstantsFromUser() const
{
	std::string message = "Enter the constants to save (separate two constants with ';'):";
	return getStringDataVectorFromUser(message);
}

void MainMenu::saveData() const
{
	std::vector<std::string> complexes = getComplexesFromUser();
	std::vector<std::string> partners = getPartnersFromUser();
	std::vector<std::string> constants = getConstantsFromUser();
}

void MainMenu::handleChoice()
{
	if (user_choice == Choices::load){
		std::cout << "Load" << std::endl;
	}
	else if (user_choice == Choices::save){
		saveData();
	}
	else if (user_choice == Choices::start){
		std::cout << "Start" << std::endl;
	}
	else if (user_choice == Choices::help){
		std::cout << "Help" << std::endl;
	}
	else if (user_choice != Choices::quit){
		user_choice = Choices::quit;
	}

}

void MainMenu::mainLoop()
{
	while (user_choice != Choices::quit)
	{
		std::cout<< menu << std::endl;
		std::cout<< "Enter your choice: " << std::endl;
		std::cin >> user_choice;
		handleChoice();
	} 
}