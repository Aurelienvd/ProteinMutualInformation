#ifndef __PROCESS_MEDIATOR_HPP
#define __PROCESS_MEDIATOR_HPP

#include "../facades/Facade.hpp"

class ProcessMediator {

public:

	virtual ~ProcessMediator();
	virtual void colleagueJobDone(Facade*) = 0; 

protected:
	ProcessMediator() {};
	virtual void createColleagues() = 0;
};

#endif /* __PROCESS_MEDIATOR_HPP */