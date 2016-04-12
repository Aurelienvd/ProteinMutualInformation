#ifndef __BIVARIATE_STRATEGY_HPP
#define __BIVARIATE_STRATEGY_HPP


#include "InformationStrategy.hpp"
#include "../TransmissionMatrix/MatrixCalculator.hpp"
#include "../RootFinder/RootFinder.hpp"
#include "../MutualInformation/BiInformationCalculator.hpp"


class BivariateStrategy: public InformationStrategy{

private:

	MatrixCalculator* error_matrix_;
	RootFinder* solver_;
	BiInformationCalculator* information_calculator_;

public:

	BivariateStrategy();
	virtual ~BivariateStrategy();

	void calculateInformationAndFillTable(std::shared_ptr<ResultTable> res) {};

};

#endif /* __BIVARIATE_STRATEGY_HPP */