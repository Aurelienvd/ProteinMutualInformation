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

GlobalProtein* ProteinsContainer::getProtein(std::string name) const
{
	GlobalProtein* protein = nullptr;
	bool found = false;
	unsigned int size = proteins_.size();
	for (unsigned int i = 0; !found && i < size; i++){
		if (proteins_.at(i)->equalsTo(name)){
			found = true;
			protein = proteins_.at(i);
		}
	}
	return protein;
}

std::vector<GlobalProtein*> ProteinsContainer::getProteins() const
{
	return proteins_;
}

ProteinComplex* ProteinsContainer::getComplexForGlobalProtein(GlobalProtein* protein, GlobalProtein* base, GlobalProtein* partner) const
{
	ProteinComplex* complex = nullptr;
	bool found = false;
	std::vector<ProteinComplex*> complexes = map_.at(protein);
	unsigned int size = complexes.size();
	for (unsigned int i = 0; !found && i < size; i++){
		if (complexes.at(i)->baseEqualsTo(base->getProtein()) && ((partner != nullptr) == (partner != nullptr && complexes.at(i)->hasAsPartner(partner->getProtein())))){
			found = true;
			complex = complexes.at(i);
		}
	}
	return complex;
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