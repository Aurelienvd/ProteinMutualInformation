#ifndef __INFORMATION_STRATEGY_HPP
#define __INFORMATION_STRATEGY_HPP

#include <memory>

#include "../ResultTable/ResultTable.hpp"
#include "../InformationProteinData/InformationProteinsContainer.hpp"

class InformationStrategy{

public:

	virtual ~InformationStrategy() = default;

	virtual void calculateInformationAndFillTable(std::shared_ptr<ResultTable> res, InformationProteinsContainer* data) = 0;    // Information table is an ADT that this strategy will fill using Information algorithms.

};


#endif /* __INFORMATION_STRATEGY_HPP */