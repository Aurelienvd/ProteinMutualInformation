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
	request_ = request;
}

std::shared_ptr<UserRequest> UI::getRequest() const
{
	return request_;
}

void UI::jobDone()
{

}