#ifndef __INFORMATION_PROCESS_DIRECTOR_HPP
#define __INFORMATION_PROCESS_DIRECTOR_HPP

#include "ProcessDirector.hpp"
#include "../facades/informationfacades/InformationProteinData.hpp"
#include "../facades/informationfacades/InformationAlgorithm.hpp"
#include "../information/InformationProteinData/InformationProteinsContainer.hpp"
#include "../information/InformationStrategy/BivariateStrategy.hpp"
#include "../information/InformationStrategy/TrivariateStrategy.hpp"
#include "../information/ResultTable/ResultTable.hpp"

#include <memory>

class InformationCalculator;


class InformationProcessDirector: public ProcessDirector {
	
	private:

		typedef AlgorithmicConstraints::Information InformationType;

		InformationCalculator* upper_facade_;
		InformationProteinData* protein_data_;
		InformationAlgorithm* algorithm_;
		InformationProteinsContainer* adt_;

		std::shared_ptr<ResultTable> res_;

		int information_type_;
		
		void createColleagues();
		void directDataJobDone();

	public:

		InformationProcessDirector(InformationCalculator* facade);
		virtual ~InformationProcessDirector();

		void startProcess(ProteinsContainer* data, AlgorithmicConstraints* constraints);
		void colleagueJobDone(Facade* facade); 




};

#endif /* __INFORMATION_PROCESS_DIRECTOR_HPP */