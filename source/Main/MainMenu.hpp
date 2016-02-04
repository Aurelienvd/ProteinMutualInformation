#ifndef __MAIN_MENU__HPP
#define __MAIN_MENU__HPP

#include <string>
#include <iostream>
#include <vector>

#define LINESIZE 65
#define MENUSIZE 10
#define SPACERSIZE 5
#define DECOYCHAR '#'


class MainMenu {

private:

	enum Choices {load = 1, start = 2, help = 3, quit = 4};
	int user_choice;
	std::string menu;

	void addHeader();
	void addLine(std::string line);
	void addSeparator();
	void addMenu();

public:

	MainMenu();

	void handleChoice() const;
	void mainLoop();

};



#endif /* __MAIN_MENU__HPP  */