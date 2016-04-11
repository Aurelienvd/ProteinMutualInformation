#ifndef __INFORMATION_CALCULATOR_HPP
#define __INFORMATION_CALCULATOR_HPP

#include "Facade.hpp"
#include "../mediators/InformationProcessDirector.hpp"
#include "../communicationdata/AlgorithmicConstraints.hpp"
#include "../protein/ProteinsContainer.hpp"


class InformationCalculator: public Facade {

	private:

		InformationProcessDirector* computation_director_;

	public:
		InformationCalculator(ProcessDirector* director);
		virtual ~InformationCalculator();

		void calculateInformation(ProteinsContainer* data, AlgorithmicConstraints* constraints);


};

#endif /* __INFORMATION_CALCULATOR_HPP */