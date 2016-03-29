#ifndef __MAIN_MENU__HPP
#define __MAIN_MENU__HPP

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>

#include "../requests/UserRequest.hpp"
#include "SaveChoiceHandler.hpp"
#include "LoadChoiceHandler.hpp"
#include "HelpChoiceHandler.hpp"
#include "StartChoiceHandler.hpp"

#define LINESIZE 65
#define MENUSIZE 12			// Add 2 to this when adding a choice, substract 2 when deleting one.
#define SPACERSIZE 5
#define DECOYCHAR '#'

class UI;

class MainMenu {

private:

	typedef UserRequest::Choices Choices;

	std::shared_ptr<UserRequest> user_request_;
	SaveChoiceHandler* save_handler_;
	LoadChoiceHandler* load_handler_;
	HelpChoiceHandler* help_handler_;
	StartChoiceHandler* start_handler_;
	UI* facade_;
	
	int user_choice;
	std::string menu;

	void addHeader();
	void addLine(std::string line);
	void addSeparator();
	void addMenu();
	void resetRequest();

public:

	MainMenu(UI* facade);
	~MainMenu();

	void handleChoice();
	void mainloop();

};



#endif /* __MAIN_MENU__HPP  */