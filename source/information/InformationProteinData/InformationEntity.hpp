
/** 
 * InformationEntity represents an information entity based on the Shannon's communication model. It has been adapted to proteins communication.
 */

#ifndef __INFORMATION_ENTITY_HPP
#define __INFORMATION_ENTITY_HPP


#include <vector>
#include <string>
#include <cstddef>

#include "../../protein/GlobalProtein.hpp"
#include "../../protein/ProteinComplex.hpp"

class InformationEntity {

	public:

		class Range;		/// Nested class representing the range which the concentration of the GlobalProtein attribute will move in.


	private:

		//------------------------------
		// Private data members
		//
		// protein_
		//		The global protein defined as the information entity. E.g., an InformationEntity for the input of p27-Cks1-Skp2 will have p27 as the protein_ data member.
		//
		// related_complexes_
		//		The complexes related with the information entity. A related complex is a complex containing the GlobalProtein protein_.
		//
		// range_
		//		The instanciation of the nested class Range.
		//
		//-----------------------------

		GlobalProtein* protein_;
		std::vector<ProteinComplex*> related_complexes_;		// All the complexes containing the entity.
		Range* range_;

	public:

		InformationEntity();
		~InformationEntity();

		//-----------------------------
		// Getters and Setters
		//-----------------------------

		/**
		 * @return A pointer to the GlobalProtein of the entity.
		 * 		   This pointer is provided by the setEntity method.
		 * 
		 * @see InformationEntity#setEntity
		 */

		GlobalProtein* getProtein() const;

		/**
		 * @return A std::vector of the protein's related complexes.
		 *
		 * @see InformationEntity#addRelatedComplex
		 */

		std::vector<ProteinComplex*> getRelatedComplexes() const;
		
		/**
		 * @return The std::vector containing all the
		 * 			possible values of the protein's concentration. This can be computed after
		 *          some initialisations.
		 * 
		 * @see InformationEntity#setInitialValue
		 * @see InformationEntity#setFinalValue
		 * @see InformationEntity#setStep
		 */

		std::vector<double> getRange() const;

		/**
		 * @return The middle value of the range.
		 *
		 * @see Range#getRange
		 */

		float getRangeMidValue() const;

		/**
		 * @return The protein's concentration.
		 *
		 * @see Range#getRangeMidValue
		 */ 

		double getProteinConcentration() const;

		/**
		 * Set the GlobalProtein of the entity to protein;
		 *
		 * @param protein A pointer to an already defined GlobalProtein.
		 */

		void setEntity(GlobalProtein* protein);

		/**
		 * Add a complex related to the GlobalProtein protein.
		 *
		 * As for now, there are no checks whether or not the complex is really related to the protein.
		 *
		 * @param complex A pointer to an already defined ProteinComplex. 
		 */

		void addRelatedComplex(ProteinComplex* complex);

		/**
		 * Set the starting value of the Range.
		 *
		 * @param val The required value.
		 */

		void setInitialValue(float val);

		/**
		 * Set the ending value of the Range.
		 *
		 * @param val The required value.
		 */

		void setFinalValue(float val);

		/**
		 * Set the step of the Range. The step determines the increment of the Range.
		 *
		 * @param step The required step. This will be iteratively added to the starting value to create the complete range.
		 */

		void setStep(float step);

		/**
		 * Set the concentration of the GlobalProtein protein.
		 *
		 * @param concent The required concentration.
		 *
		 * @see GlobalProtein#setTotalConcentration
		 */

		void setProteinConcentration(double concent);

		//------------------------------------------
		// Nested Range class.
		//------------------------------------------

		/**
		 * Range represents the range of values that the GlobalProtein of an InformationEntity can take.
		 *
		 * A Range object is specific to an InformationEntity.
		 */

		class Range{

			private:

				//---------------------------------
				// Private data members.
				//
				// initial_value_
				//    The starting value of the range.
				//
				// final_value_
				//    The end value of the range.
				//
				// step_
				//    The increment of the range value.
				//
				//---------------------------------

				float initial_value_;
				float final_value_;
				float step_;

				friend class InformationEntity;

			public:

				//---------------------------------
				// Getters and Setters
				//---------------------------------

				/**
				 * Get the Range as a std::vector of double values. These values indicates
				 * the possible values of a protein concentration.
				 *
				 * @return A std::vector of double.
				 *
				 * @see InformationEntity
				 */

				std::vector<double> getRange() const;

				/**
				 * Get the middle value of the range.
				 *
				 * @return The middle value of the range.
				 *
				 * @see InformationEntity
				 */

				float getRangeMidValue() const;

				/**
		 		 * Set the starting value of the Range.
		 		 *
		 		 * @param value The required value.
		 		 *
		 		 * @see InformationEntity
		 		 */

				void setInitialValue(float value) {initial_value_ = value;}

				/**
		 		 * Set the ending value of the Range.
		 		 *
		 		 * @param value The required value.
		 		 *
		 		 * @see InformationEntity
		 		 */

				void setFinalValue(float value) {final_value_ = value;}

				/**
		 		 * Set the step of the Range. The step determines the increment of the Range.
				 *
				 * @param step The required step. This will be iteratively added to the starting value to create the complete range.
				 *
				 * @see InformationEntity
				 */

				void setStep(float step) {step_ = step;}

		};

};

#endif /* __INFORMATION_ENTITY_HPP */