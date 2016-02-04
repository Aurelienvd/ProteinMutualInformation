#ifndef __BIVARIATE_STRATEGY_HPP
#define __BIVARIATE_STRATEGY_HPP


#include "InformationStrategy.hpp"
#include "../Transmission Matrix/MatrixCalculator.hpp"
#include "../RootFinder/RootFinder.hpp"
#include "../Mutual Information/BiInformationCalculator.hpp"


class BivariateStrategy: public InformationStrategy{

private:

	MatrixCalculator* error_matrix_;
	RootFinder* solver_;
	BiInformationCalculator* information_calculator_;

public:

	BivariateStrategy();

	void calculateInformationTable(/*Information Table*/);

};

#endif /* __BIVARIATE_STRATEGY_HPP */