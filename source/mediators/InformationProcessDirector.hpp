#ifndef __INFORMATION_PROCESS_DIRECTOR_HPP
#define __INFORMATION_PROCESS_DIRECTOR_HPP

#include "ProcessDirector.hpp"
#include "../facades/informationfacades/InformationProteinData.hpp"
#include "../information/InformationProteinData/InformationProteinsContainer.hpp"

class InformationCalculator;


class InformationProcessDirector: public ProcessDirector {
	
	private:

		InformationCalculator* upper_facade_;
		InformationProteinData* protein_data_;
		InformationProteinsContainer* adt_;
		
		void createColleagues();

	public:

		InformationProcessDirector(InformationCalculator* facade);
		virtual ~InformationProcessDirector();

		void startProcess(ProteinsContainer* data, AlgorithmicConstraints* constraints);
		void colleagueJobDone(Facade* facade); 




};

#endif /* __INFORMATION_PROCESS_DIRECTOR_HPP */