
/**
 * This class provides an interface to compute information related results such as mutual information or transmission error.
 */


#ifndef __INFORMATION_STRATEGY_HPP
#define __INFORMATION_STRATEGY_HPP

#include <memory>

#include "../ResultTable/ResultTable.hpp"
#include "../InformationProteinData/InformationProteinsContainer.hpp"

class InformationStrategy{

public:

	virtual ~InformationStrategy() = default;

	/**
	 * Calculate information results and saved them inside an ADT, a ResultTable instance.
	 *
	 * @param res A std::shared_ptr to a ResultTable instance that will be filled by the strategy's underlying algorithms.
	 *
	 * @param data A pointer to an InformationProteinsContainer instance that has been created by the InformationProteinsContainerBuilder.
	 *
	 * @param data_changed Indicates if the data contained inside the InformationProteinsContainer instance has changed since the last call.
	 *
	 * @see ResultTable
	 * @see InformationProteinsContainer
	 */

	virtual void calculateInformationAndFillTable(std::shared_ptr<ResultTable> res, std::shared_ptr<InformationProteinsContainer> data, bool data_changed) = 0;

};


#endif /* __INFORMATION_STRATEGY_HPP */