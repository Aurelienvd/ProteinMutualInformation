#include "MainMenu.hpp"
#include "../facades/UI.hpp"

MainMenu::MainMenu(UI* facade): user_request_(std::make_shared<UserRequest>()), save_handler_(new SaveChoiceHandler()), load_handler_(new LoadChoiceHandler()), 
								help_handler_(new HelpChoiceHandler()), start_handler_(new StartChoiceHandler()), facade_(facade)
{
	addHeader();
	addMenu();
}

MainMenu::~MainMenu()
{
	delete save_handler_;
	delete help_handler_;
	delete load_handler_;
	delete start_handler_;
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

void MainMenu::displayMessage(std::string msg) const
{
	std::cout << msg << std::endl;
}

void MainMenu::resetRequest()
{
	user_request_.reset();
	user_request_ = std::make_shared<UserRequest>();
}

void MainMenu::handleChoice()
{
	if (user_choice == Choices::load){
		load_handler_->handleChoice();
		user_request_->setRequestData(load_handler_->getRequestData());
		user_request_->setUserChoice(Choices::load);
		facade_->setRequest(user_request_);
	}
	else if (user_choice == Choices::save){
		save_handler_->handleChoice();
		user_request_->setRequestData(save_handler_->getRequestData());
		user_request_->setUserChoice(Choices::save);
		facade_->setRequest(user_request_);
	}
	else if (user_choice == Choices::start){
		start_handler_->handleChoice();
		user_request_->setRequestData(start_handler_->getRequestData());
		user_request_->setUserChoice(Choices::start);
		facade_->setRequest(user_request_);
	}
	else if (user_choice == Choices::help){
		help_handler_->handleChoice();
	}
	else if (user_choice != Choices::quit){
		user_choice = Choices::quit;
	}
	resetRequest();

}

void MainMenu::mainloop()
{
	while (user_choice != Choices::quit)
	{
		std::cout<< menu << std::endl;
		std::cout<< "Enter your choice: ";
		std::cin >> user_choice;
		handleChoice();
	} 
}