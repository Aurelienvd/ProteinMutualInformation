
/**
 * A Facade that will construct information related ADT.
 */


#ifndef __INFORMATION_PROTEIN_DATA_HPP
#define __INFORMATION_PROTEIN_DATA_HPP


#include <cstddef>

#include "../Facade.hpp"
#include "../../information/InformationProteinData/InformationProteinsContainerBuilder.hpp"
#include "../../protein/ProteinsContainer.hpp"
#include "../../communicationdata/AlgorithmicConstraints.hpp"


class InformationProteinData : public Facade {

	private:

		//---------------------------
		// Private data members
		//---------------------------
		//
		// adt_builder_
		//		The builder of the ADT.

		InformationProteinsContainerBuilder* adt_builder_;

	public:

		/** @name Constructors */
		//@{
		/** The default constructor.
		 *
		 * @see Facade
		 */
		//@} 

		InformationProteinData(ProcessDirector* director);
		virtual ~InformationProteinData();

		/**
		 * Construct an ADT that contains the data that will be used by the information computation algorithms.
		 *
		 * Call a builder to build the ADT.
		 *
		 * @param data A pointer to the data available inside the system.
		 * @param constraints A pointer to the algorithmic constraints that will be respected by the algorithms.
		 *
		 * @see ProteinsContainerBuilder
		 * @see AlgorithmicConstraints
		 */

		void constructADT(ProteinsContainer* data, AlgorithmicConstraints* constraints);

		/**
		 * Get the ADT constructed.
		 *
		 * @return A pointer to the ADT constructed.
		 *
		 * @see InformationProteinsContainer
		 */

		InformationProteinsContainer* getADT() const; 


};

#endif  /* __INFORMATION_PROTEIN_DATA_HPP  */