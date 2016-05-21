
/**
 * A Facade that computes information related results.
 */


#ifndef __INFORMATION_ALGORITHM_HPP
#define __INFORMATION_ALGORITHM_HPP

#include "../Facade.hpp"
#include "../../information/InformationStrategy/InformationStrategy.hpp"
#include "../../information/ResultTable/ResultTable.hpp"
#include "../../information/InformationProteinData/InformationProteinsContainer.hpp"
#include "../../exceptions/WrongInputDataException.hpp"

#include <cstddef>
#include <memory>


class InformationAlgorithm : public Facade {

	private:

		//-----------------------------
		// Private data members
		//-----------------------------
		//
		// strategy_
		//		A pointer to a Strategy object that contains the computation algorithms.
		//
		// data_changed_
		//		Indicate if the data has changed since the last execution.

		std::shared_ptr<InformationStrategy> strategy_;
		bool data_changed_;
		void checkData(std::shared_ptr<InformationProteinsContainer> data) const; 

	public:

		/** @name Constructors */
		//@{
		/** The default constructor
		 *
		 * @see Facade
		 */
		//@}

		InformationAlgorithm(ProcessDirector* director);

		/**
		 * Set the strategy that will be used to compute results.
		 *
		 * @param A pointer to an InformationStrategy.
		 *
		 * @see InformationStrategy
		 */

		void setStrategy(std::shared_ptr<InformationStrategy> strat);

		/**
		 * Start the Algorithm (i.e. the information computation algorithm).
		 *
		 * @param res An ADT that will be filled with algorithmic results.
		 * @param data An ADT that will contained the data required by the algorithm.
		 *
		 * @see ResultTable
		 * @see InformationProteinsContainer
		 */

		void startAlgorithm(std::shared_ptr<ResultTable> res, std::shared_ptr<InformationProteinsContainer> data);

};


#endif /* __INFORMATION_ALGORITHM_HPP  */