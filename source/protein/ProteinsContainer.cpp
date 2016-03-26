#include "ProteinsContainer.hpp"

ProteinsContainer::ProteinsContainer(GlobalProtein* protein)
{
	proteins_.push_back(protein);
	map_.insert(proteins_pair(protein, std::vector<ProteinComplex*>()));
}

ProteinsContainer::ProteinsContainer(std::vector<GlobalProtein*> proteins): proteins_(proteins)
{
	for (GlobalProtein* protein : proteins){
		map_.insert(proteins_pair(protein, std::vector<ProteinComplex*>()));
	}
}

std::vector<GlobalProtein*> ProteinsContainer::getProteins() const
{
	return proteins_;
}

std::vector<ProteinComplex*> ProteinsContainer::getComplexesForGlobalProtein(GlobalProtein* protein) const
{
	return map_.at(protein);
}

void ProteinsContainer::addProteinComplexForProtein(GlobalProtein* protein, ProteinComplex* complex)
{
	std::vector<ProteinComplex*> complexes = map_.at(protein);
	complexes.push_back(complex);
	map_[protein] = complexes;
}