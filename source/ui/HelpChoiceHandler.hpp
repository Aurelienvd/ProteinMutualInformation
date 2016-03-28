#ifndef __HELP_CHOICE_HANDLER_HPP
#define __HELP_CHOICE_HANDLER_HPP

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

#define HELPTEXT "help.txt"

class HelpChoiceHandler {

	private:

		std::string text_;

		void readFile();
		void displayText() const;

	public:

		void handleChoice();


};

#endif /* __HELP_CHOICE_HANDLER_HPP */