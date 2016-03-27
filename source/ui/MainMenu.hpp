#ifndef __MAIN_MENU__HPP
#define __MAIN_MENU__HPP

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

#define LINESIZE 65
#define MENUSIZE 12			// Add 2 to this when adding a choice, substract 2 when deleting one.
#define SPACERSIZE 5
#define DECOYCHAR '#'
#define DELIMITER ';'


class MainMenu {

private:

	enum Choices {load = 1,  save = 2, start = 3, help = 4, quit = 5};
	int user_choice;
	std::string menu;

	void addHeader();
	void addLine(std::string line);
	void addSeparator();
	void addMenu();
	void saveData() const;
	std::vector<std::string> split(std::string str) const;
	std::vector<std::string> getComplexesFromUser() const;
	std::vector<std::string> getPartnersFromUser() const;
	std::vector<std::string> getConstantsFromUser() const;
	std::vector<std::string> getStringDataVectorFromUser(std::string message) const;

public:

	MainMenu();

	void handleChoice();
	void mainLoop();

};



#endif /* __MAIN_MENU__HPP  */