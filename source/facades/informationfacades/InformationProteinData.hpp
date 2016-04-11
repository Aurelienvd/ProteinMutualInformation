#ifndef __INFORMATION_PROTEIN_DATA_HPP
#define __INFORMATION_PROTEIN_DATA_HPP


#include <cstddef>

#include "../Facade.hpp"
#include "../../information/InformationProteinData/InformationProteinsContainerBuilder.hpp"
#include "../../protein/ProteinsContainer.hpp"
#include "../../communicationdata/AlgorithmicConstraints.hpp"


class InformationProteinData : public Facade {

	private:

		InformationProteinsContainerBuilder* adt_builder_;

	public:

		InformationProteinData(ProcessDirector* director);
		virtual ~InformationProteinData();

		void constructADT(ProteinsContainer* data, AlgorithmicConstraints* constraints);
		InformationProteinsContainer* getADT() const; 


};

#endif  /* __INFORMATION_PROTEIN_DATA_HPP  */