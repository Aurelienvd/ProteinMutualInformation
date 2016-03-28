#include "UserRequest.hpp"


int UserRequest::getUserChoice() const
{
	return user_choice_;
}

void UserRequest::setUserChoice(int user_choice)
{
	user_choice_ = user_choice;
}