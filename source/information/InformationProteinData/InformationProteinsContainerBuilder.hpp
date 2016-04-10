#ifndef __INFORMATION_PROTEINS_CONTAINER_BUILDER_HPP
#define __INFORMATION_PROTEINS_CONTAINER_BUILDER_HPP

#include <cstddef>

#include "InformationProteinsContainer.hpp"
#include "InformationEntity.hpp"
#include "../../communicationdata/AlgorithmicConstraints.hpp"
#include "../../protein/ProteinsContainer.hpp"

class InformationProteinsContainerBuilder {

	private:

		ProteinsContainer*	data_;
		AlgorithmicConstraints* constraints_;
		InformationProteinsContainer* information_proteins_data_;
		InformationEntity* input_;
		InformationEntity* output_;
		InformationEntity* channel_;

		void buildCommonPart(AlgorithmicConstraints::ProteinConstraints* constraints, InformationEntity* entity);

	public:

		InformationProteinsContainerBuilder(AlgorithmicConstraints* constraints, ProteinsContainer* data);
		void buildInput();
		void buildOutput();
		void buildChannel();
		void buildInformationProteinsContainer();
		InformationProteinsContainer* getInformationProteinsData() const;

};

#endif /* __INFORMATION_PROTEINS_CONTAINER_BUILDER_HPP */