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

		typedef AlgorithmicConstraints::Information InformationType;

		ProteinsContainer*	data_;
		AlgorithmicConstraints* constraints_;
		InformationProteinsContainer* information_proteins_data_;
		InformationEntity* input_;
		InformationEntity* output_;
		InformationEntity* channel_;

		void buildCommonPart(AlgorithmicConstraints::ProteinConstraints* constraints, InformationEntity* entity);
		void addComplexVersionOfEntity(InformationEntity* entity);

		
		// Adds one sided complex (if the input is A, the channel is B and the output is C, adds the complex A-B to the InformationEntity A).

		void addOneSidedCommunicationComplex(InformationEntity* entity, AlgorithmicConstraints::ProteinConstraints* partner);
		
		void addWholeCommunicationComplex();			// Adds the whole communication complex (this adds the complex A-B-C)

	public:

		InformationProteinsContainerBuilder(ProteinsContainer* data, AlgorithmicConstraints* constraints);
		void buildInput();
		void buildOutput();
		void buildChannel();
		void buildInformationProteinsContainer();
		InformationProteinsContainer* getInformationProteinsData() const;

};

#endif /* __INFORMATION_PROTEINS_CONTAINER_BUILDER_HPP */