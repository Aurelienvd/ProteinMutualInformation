#include "UI.hpp"

UI::UI(ProcessDirector* director): Facade(director), menu_(new MainMenu(this)) {}

UI::~UI()
{
	delete menu_;
}

void UI::mainloop()
{
	menu_->mainloop();
}

void UI::setRequest(std::shared_ptr<UserRequest> request)
{
	request_.reset();
	request_ = request;
	jobDone();
}

std::shared_ptr<UserRequest> UI::getRequest() const
{
	return request_;
}

void UI::displayMessage(std::string msg) const
{
	menu_->displayMessage(msg);
}

void UI::jobDone()
{
	Facade::jobDone();
}