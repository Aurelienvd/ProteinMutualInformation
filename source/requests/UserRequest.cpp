#include "UserRequest.hpp"

UserRequest::UserRequest(): data_(nullptr) {}

UserRequest::~UserRequest()
{
	delete data_;
}

int UserRequest::getUserChoice() const
{
	return user_choice_;
}

void UserRequest::setUserChoice(int user_choice)
{
	user_choice_ = user_choice;
}

RequestData* UserRequest::getRequestData() const
{
	return data_;
}

void UserRequest::setRequestData(RequestData* data)
{
	data_ = data;
}