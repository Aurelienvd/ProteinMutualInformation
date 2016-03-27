#ifndef __PROTEIN_DATA_HPP
#define __PROTEIN_DATA_HPP


#include "../protein/ProteinsContainerBuilder.hpp"
#include "../datamanaging/ConcreteStream.hpp"
#include "Facade.hpp"

class ProteinData: public Facade {

private:

	ProteinsContainerBuilder* protein_adt_builder_;

public:

	ProteinData(ProcessMediator* mediator);

	void constructADT(ConcreteStream* data);
	ProteinsContainer* getADT() const;

};

#endif /* __PROTEIN_DATA_HPP  */