#ifndef __BIVARIATE_STRATEGY_HPP
#define __BIVARIATE_STRATEGY_HPP


#include "InformationStrategy.hpp"
#include "../TransmissionMatrix/MatrixCalculator.hpp"
#include "../RootFinder/RootFinder.hpp"
#include "../MutualInformation/BiInformationCalculator.hpp"

#include <vector>

#define BIONESIDEDCOMPLEXSIZE 2
#define BICOMMUNICATIONSYSTEMSIZE 3


class BivariateStrategy: public InformationStrategy{

private:

	MatrixCalculator* error_matrix_;
	RootFinder* solver_;
	BiInformationCalculator* information_calculator_;
	double kd1_;
	double kd2_;
	double kd3_;

	void initiateSolver(InformationProteinsContainer* data);
	void assignateKD(InformationProteinsContainer* data);

public:

	BivariateStrategy();
	virtual ~BivariateStrategy();

	void calculateInformationAndFillTable(std::shared_ptr<ResultTable> res, InformationProteinsContainer* data, bool data_changed);

};

#endif /* __BIVARIATE_STRATEGY_HPP */