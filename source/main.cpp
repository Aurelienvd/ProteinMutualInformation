#include <iostream>

#include "ui/MainMenu.hpp"


using namespace std;

int main(int argc, char** argv){

	MainMenu* menu = new MainMenu();

	menu->mainLoop();
	delete menu;

	return 0;
}