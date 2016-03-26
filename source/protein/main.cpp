#include <iostream>

#include "ProteinsContainer.hpp"

using namespace std;

int main (int argc, char** argv)
{
	GlobalProtein* protein = new GlobalProtein("p27"); 
	ProteinsContainer* container = new ProteinsContainer(protein);
	ProteinComplex* complex = new ProteinComplex("Cks1", "p27", 50);
	container->addProteinComplexForProtein(protein, complex);

	for (ProteinComplex* comp : container->getComplexesForGlobalProtein(protein)){
		cout << comp->getBase() << endl;
	}

	delete protein;
	delete complex;
	delete container;
	return 0;
}