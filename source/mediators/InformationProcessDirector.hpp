#ifndef __INFORMATION_PROCESS_DIRECTOR_HPP
#define __INFORMATION_PROCESS_DIRECTOR_HPP

#include "ProcessDirector.hpp"

class InformationCalculator;


class InformationProcessDirector: public ProcessDirector {
	
	private:

		InformationCalculator* upper_facade_;
		
		void createColleagues();

	public:

		InformationProcessDirector(InformationCalculator* facade);
		virtual ~InformationProcessDirector();

		void colleagueJobDone(Facade* facade); 




};

#endif /* __INFORMATION_PROCESS_DIRECTOR_HPP */