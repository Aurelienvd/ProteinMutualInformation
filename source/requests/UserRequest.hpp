#ifndef __USER_REQUEST_HPP
#define __USER_REQUEST_HPP

#include <string>
#include <cstddef>

#include "RequestData.hpp"

class UserRequest {

private:
	
	RequestData* data_;
	int user_choice_;

public:

	enum Choices {load = 1,  save = 2, start = 3, help = 4, quit = 5};

	UserRequest();
	~UserRequest();

	int getUserChoice() const;
	RequestData* getRequestData() const;
	void setUserChoice(int user_choice);
	void setRequestData(RequestData* data);
};

#endif /* __USER_REQUEST_HPP */