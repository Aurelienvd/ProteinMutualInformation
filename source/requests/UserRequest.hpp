#ifndef __USER_REQUEST_HPP
#define __USER_REQUEST_HPP

#include <string>

class UserRequest {

private:
	
	int user_choice_;

public:

	enum Choices {load = 1,  save = 2, start = 3, help = 4, quit = 5};

	int getUserChoice() const;
	void setUserChoice(int user_choice);
};

#endif /* __USER_REQUEST_HPP */