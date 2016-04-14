
/**
 * An InformationProteinsContainerBuilder is a builder defined to build an instance of the InformationProteinsContainer.
 *
 * To build an InformationProteinsContainer, the builder needs data created by the protein module and the algorithmic
 * constraints as defined inside the communicationdata module. The builder will filter the data given according to the constraints.
 * The product will be the InformationProteinsContainer instance that represents the subsystem defined by the algorithmic constraints.
 * The parts of the product are InformationEntity instances.
 * 
 * The InformationProteinsContainer instance will then be used by other classes inside the information module.
 *
 *
 * @see InformationEntity
 * @see InformationProteinsContainer
 * @see AlgorithmicConstraints
 * @see ProteinsContainer
 */

#ifndef __INFORMATION_PROTEINS_CONTAINER_BUILDER_HPP
#define __INFORMATION_PROTEINS_CONTAINER_BUILDER_HPP


#include <cstddef>
#include <vector>
#include <memory>

#include "InformationProteinsContainer.hpp"
#include "InformationEntity.hpp"
#include "../../communicationdata/AlgorithmicConstraints.hpp"
#include "../../protein/ProteinsContainer.hpp"

class InformationProteinsContainerBuilder {

	private:

		//---------------------------------
		// Private data members
		//---------------------------------
		//
		// data_
		// 		A ProteinsContainer that contains all the data available.
		//
		// constraints_
		//      Algorithmics constraints that will indicate what to build.
		//
		// information_proteins_data_
		//		The product of the building process.
		//
		// input_
		//		A part of the product.
		//
		// output_
		//		A part of the product.
		//
		// channel_
		//		A part of the product.

		typedef AlgorithmicConstraints::Information InformationType;

		ProteinsContainer*	data_;
		AlgorithmicConstraints* constraints_;
		InformationProteinsContainer* information_proteins_data_;
		InformationEntity* input_;
		InformationEntity* output_;
		InformationEntity* channel_;

		//-------------------------------------
		// Private member functions
		//-------------------------------------
		//
		// buildCommonPart
		//		build the common part of the product parts.
		//
		// addComplexVersionOfEntity
		//		Add a ProteinComplex version of an InformationEntity protein_.
		//
		// addOneSidedCommunicationComplex
		//		Adds one sided complex (if the input is A, the channel is B and the output is C, adds the complex A-B to the InformationEntity A).
		//
		// addWholeCommunicationComplex
		//		Adds the whole communication complex (this adds the complex A-B-C).

		void buildCommonPart(AlgorithmicConstraints::ProteinConstraints* constraints, InformationEntity* entity);
		void addComplexVersionOfEntity(InformationEntity* entity);
		void addOneSidedCommunicationComplex(InformationEntity* entity, AlgorithmicConstraints::ProteinConstraints* partner);
		void addWholeCommunicationComplex();

	public:

		/** @name Constructors */
		//@{
		/** The default constructor. It takes a ProteinsContainer instance representing the data and an AlgorithmicConstraints instance representing the constraints.  */
		InformationProteinsContainerBuilder(ProteinsContainer* data, AlgorithmicConstraints* constraints);
		//@}

		/**
		 * Build the input part of the product.
		 */

		void buildInput();

		/**
		 * Build the output part of the product.
		 */

		void buildOutput();

		/**
		 * Build the channel part of the product.
		 */

		void buildChannel();

		/**
		 * Build the product.
		 */

		void buildInformationProteinsContainer();

		/**
		 * Get the product.
		 *
		 * @return The product of the building process.
		 *
		 * @see InformationProteinsContainer
		 */

		InformationProteinsContainer* getInformationProteinsData() const;

};

#endif /* __INFORMATION_PROTEINS_CONTAINER_BUILDER_HPP */