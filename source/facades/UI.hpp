#ifndef __UI_HPP
#define __UI_HPP

#include "Facade.hpp"

class UI : public Facade {

public:

	UI(ProcessMediator* mediator);
	virtual ~UI();

};

#endif /* __UI_HPP */