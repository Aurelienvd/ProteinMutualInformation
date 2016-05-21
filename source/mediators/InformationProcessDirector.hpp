
/**
 * A mediator class that manages the information process of the program.
  *
 * An InformationProcessDirector will direct the information related operations, information data creation, algorithmic results save.
 */


#ifndef __INFORMATION_PROCESS_DIRECTOR_HPP
#define __INFORMATION_PROCESS_DIRECTOR_HPP

#include "ProcessDirector.hpp"
#include "../facades/informationfacades/InformationProteinData.hpp"
#include "../facades/informationfacades/InformationAlgorithm.hpp"
#include "../information/InformationProteinData/InformationProteinsContainer.hpp"
#include "../information/InformationStrategy/BivariateStrategy.hpp"
#include "../information/InformationStrategy/TrivariateStrategy.hpp"
#include "../information/ResultTable/ResultTable.hpp"
#include "../information/ResultTable/ResultTableWritter.hpp"

#include "../constants/constants.hpp"
#include "../exceptions/WrongInputDataException.hpp"

#include <memory>
#include <iostream>

class InformationCalculator;


class InformationProcessDirector: public ProcessDirector {
	
	private:

		typedef AlgorithmicConstraints::Information InformationType;

		//-----------------------
		// Private data members
		//-----------------------
		//
		// upper_facade_
		//		see InformationCalculator Facade
		//
		// protein_data_
		//		see InformationProteinData
		//
		// algorithm_
		//		see InformationAlgorithm Facade
		//
		// adt_
		//		see InformationProteinsContainer ADT
		//
		// information_type_
		//		The type of the algorithm that will be executed.

		InformationCalculator* upper_facade_;
		InformationProteinData* protein_data_;
		InformationAlgorithm* algorithm_;
		std::shared_ptr<InformationProteinsContainer> adt_;

		std::shared_ptr<ResultTable> res_;
		std::unique_ptr<ResultTableWritter> res_writter_;

		int information_type_;

		//--------------------------
		// Private member functions
		//--------------------------
		//
		// createColleagues
		//		see ProcessDirector#createColleagues
		//
		// directDataJobDone
		//		Direct when the job of the protein data creation module is done.
		
		void createColleagues();
		void directDataJobDone();
		void saveResultTable() const;

	public:

		/** @name Constructors */
		//@{
		/**
		 * The default constructor.
		 *
		 * @param facade A pointer to parent class.
		 *
		 * @see InformationCalculator
		 */
		//@}

		InformationProcessDirector(InformationCalculator* facade);
		virtual ~InformationProcessDirector();

		/**
		 * Start the Information process.
		 *
		 * @param data The data available for the algorithms.
		 * @param constraints The constraints of the algorithms.
		 *
		 * @see ProteinsContainer
		 * @see AlgorithmicConstraints
		 */

		void startProcess(std::shared_ptr<ProteinsContainer> data, std::shared_ptr<AlgorithmicConstraints> constraints);

		/**
		 * Call the next of the process when a colleague's job is done.
		 *
		 * @param facade The colleague that just finished it's job.
		 */
		 
		void colleagueJobDone(Facade* facade);

		/**
		 * Get the result of the algorithm's execution.
		 *
		 * @return a shared_ptr to a ResultTable.
		 */

		std::shared_ptr<ResultTable> getResult() const;




};

#endif /* __INFORMATION_PROCESS_DIRECTOR_HPP */