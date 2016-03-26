#include "ProteinsContainer.hpp"

ProteinsContainer::ProteinsContainer(std::vector<GlobalProtein*> proteins): proteins_(proteins)
{
	for (GlobalProtein* protein : proteins){
		map_.insert(proteins_pair(protein, std::vector<ProteinComplex*>()));
	}
}