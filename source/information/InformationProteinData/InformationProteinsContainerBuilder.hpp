
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
#include "../../constants/constants.hpp"

class InformationProteinsContainerBuilder {

	typedef std::vector<std::shared_ptr<InformationEntity>> infovector;

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
		//
		// inputs_
		//		A part of the product (replaces input_ if defined). (for multivariate info)

		typedef AlgorithmicConstraints::Information InformationType;

		std::shared_ptr<ProteinsContainer>	data_;
		std::shared_ptr<AlgorithmicConstraints> constraints_;
		std::shared_ptr<InformationProteinsContainer> information_proteins_data_;
		std::shared_ptr<InformationEntity> input_;
		std::shared_ptr<InformationEntity> output_;
		std::shared_ptr<InformationEntity> channel_;
		infovector inputs_;

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
		//
		// addAllCommunicationComplexes
		//		Adds all the communication complexes of size between min and max. (for multivariate info).

		void buildCommonPart(std::shared_ptr<AlgorithmicConstraints::ProteinConstraints> constraints, std::shared_ptr<InformationEntity> entity);
		void addComplexVersionOfEntity(std::shared_ptr<InformationEntity> entity);
		void addOneSidedCommunicationComplex(std::shared_ptr<InformationEntity> entity, std::shared_ptr<AlgorithmicConstraints::ProteinConstraints> partner);
		void addAllCommunicationComplexes(std::shared_ptr<InformationEntity> entity, unsigned int min, unsigned int max); 
		void addWholeCommunicationComplex();

	public:

		/** @name Constructors */
		//@{
		/** The default constructor. It takes a ProteinsContainer instance representing the data and an AlgorithmicConstraints instance representing the constraints.  */
		InformationProteinsContainerBuilder(std::shared_ptr<ProteinsContainer> data, std::shared_ptr<AlgorithmicConstraints> constraints);
		//@}

		/**
		 * Build the input part of the product.
		 */

		void buildInput();

		/**
		 * Build the inputs part of the product. (for multivariate info).
		 */

		void buildInputs();

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

		std::shared_ptr<InformationProteinsContainer> getInformationProteinsData() const;

};

#endif /* __INFORMATION_PROTEINS_CONTAINER_BUILDER_HPP */