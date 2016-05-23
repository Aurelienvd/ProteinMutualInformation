
/**
 * A facade that starts the information computation process.
 */

#ifndef __INFORMATION_CALCULATOR_HPP
#define __INFORMATION_CALCULATOR_HPP

#include "Facade.hpp"
#include "../mediators/InformationProcessDirector.hpp"
#include "../communicationdata/AlgorithmicConstraints.hpp"
#include "../protein/ProteinsContainer.hpp"
#include "../information/ResultTable/ResultTable.hpp"


class InformationCalculator: public Facade {

	private:

		//----------------------
		// Private data members
		//----------------------
		//
		// computation_director_
		//		A pointer to a director directing the information computation process.

		std::unique_ptr<InformationProcessDirector> computation_director_;

	public:

		/** @name Constructors */
		//@{
		/**	Default constructor.
		 *
		 * @see Facade
		 */
		//@}

		InformationCalculator(ProcessDirector* director);
		virtual ~InformationCalculator() = default;

		/**
		 * Start the information computation process.
		 *
		 * @param data The data available inside the system.
		 * @param constraints The algorithmic constraints that will be respected by the computation process.
		 *
		 * @see ProteinData
		 * @see AlgorithmicConstraints
		 */

		void calculateInformation(std::shared_ptr<ProteinsContainer> data, std::shared_ptr<AlgorithmicConstraints> constraints, std::string resfilename);

		/**
		 * @see InformationProcessDirector#getResult
		 */

		std::shared_ptr<ResultTable> getResult() const;


};

#endif /* __INFORMATION_CALCULATOR_HPP */