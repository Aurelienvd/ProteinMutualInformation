#ifndef __UI_HPP
#define __UI_HPP

#include "Facade.hpp"

class UI : public Facade {

public:

	UI(ProcessDirector* director);
	virtual ~UI();

};

#endif /* __UI_HPP */