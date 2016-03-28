#ifndef __PROCESS_DIRECTOR_HPP
#define __PROCESS_DIRECTOR_HPP

#include "../facades/Facade.hpp"

class ProcessDirector {

public:

	virtual ~ProcessDirector() = default;
	virtual void colleagueJobDone(Facade*) = 0; 

protected:
	ProcessDirector() = default;
	virtual void createColleagues() = 0;
};

#endif /* __PROCESS_DIRECTOR_HPP */