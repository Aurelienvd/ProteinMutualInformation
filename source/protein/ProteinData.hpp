#ifndef __PROTEIN_DATA_HPP
#define __PROTEIN_DATA_HPP


#include "ProteinsContainerBuilder.hpp"
#include "../DataManaging/ConcreteStream.hpp"

class ProteinData {

private:

	ProteinsContainerBuilder* protein_adt_builder_;

public:

	ProteinData();
	~ProteinData();

	void constructADT(ConcreteStream* data);
	ProteinsContainer* getADT() const;

};

#endif /* __PROTEIN_DATA_HPP  */