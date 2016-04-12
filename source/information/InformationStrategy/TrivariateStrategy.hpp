#ifndef __TRIVARIATE_STRATEGY_HPP
#define __TRIVARIATE_STRATEGY_HPP

#include "InformationStrategy.hpp"


class TrivariateStrategy: public InformationStrategy{

public:

	virtual ~TrivariateStrategy() = default;

	void calculateInformationAndFillTable(std::shared_ptr<ResultTable> res) {};


};


#endif /* __TRIVARIATE_STRATEGY_HPP */