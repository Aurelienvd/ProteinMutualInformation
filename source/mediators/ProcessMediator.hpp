#ifndef __PROCESS_MEDIATOR_HPP
#define __PROCESS_MEDIATOR_HPP

#include "../facades/Facade.hpp"

class ProcessMediator {

public:

	virtual ~ProcessMediator() = default;
	virtual void colleagueJobDone(Facade*) = 0; 

protected:
	ProcessMediator() = default;
	virtual void createColleagues() = 0;
};

#endif /* __PROCESS_MEDIATOR_HPP */