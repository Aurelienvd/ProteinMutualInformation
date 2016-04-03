#ifndef __INFORMATION_PROCESS_DIRECTOR_HPP
#define __INFORMATION_PROCESS_DIRECTOR_HPP

#include "ProcessDirector.hpp"


class InformationProcessDirector: public ProcessDirector {
	
	private:
		
		void createColleagues();

	public:

		void colleagueJobDone(Facade* facade); 




};

#endif /* __INFORMATION_PROCESS_DIRECTOR_HPP */