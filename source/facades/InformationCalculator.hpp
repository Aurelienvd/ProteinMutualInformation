#ifndef __INFORMATION_CALCULATOR_HPP
#define __INFORMATION_CALCULATOR_HPP

#include "Facade.hpp"
#include "../mediators/InformationProcessDirector.hpp"


class InformationCalculator: public Facade {

	private:

		InformationProcessDirector* computation_director_;

	public:
		InformationCalculator(ProcessDirector* director);
		virtual ~InformationCalculator();


};

#endif /* __INFORMATION_CALCULATOR_HPP */