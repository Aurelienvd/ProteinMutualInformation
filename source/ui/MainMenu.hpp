#ifndef __MAIN_MENU__HPP
#define __MAIN_MENU__HPP

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

#include "../requests/UserRequest.hpp"
#include "SaveChoiceHandler.hpp"
#include "LoadChoiceHandler.hpp"
#include "HelpChoiceHandler.hpp"

#define LINESIZE 65
#define MENUSIZE 12			// Add 2 to this when adding a choice, substract 2 when deleting one.
#define SPACERSIZE 5
#define DECOYCHAR '#'


class MainMenu {

private:

	typedef UserRequest::Choices Choices;

	UserRequest* user_request_;
	SaveChoiceHandler* save_handler_;
	LoadChoiceHandler* load_handler_;
	HelpChoiceHandler* help_handler_;
	int user_choice;
	std::string menu;

	void addHeader();
	void addLine(std::string line);
	void addSeparator();
	void addMenu();

public:

	MainMenu();
	~MainMenu();

	void handleChoice();
	void mainLoop();

};



#endif /* __MAIN_MENU__HPP  */