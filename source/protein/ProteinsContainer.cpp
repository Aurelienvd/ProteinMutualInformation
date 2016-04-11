#include "ProteinsContainer.hpp"
#include <iostream>

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

GlobalProtein* ProteinsContainer::getProtein(std::shared_ptr<Protein> name) const
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

bool ProteinsContainer::complexEqualsTo(ProteinComplex* complex, std::shared_ptr<Protein> base, GlobalProtein* partner) const
{
	bool testContains = complex->baseEqualsTo(base) && ((partner != nullptr) == (partner != nullptr && complex->hasAsPartner(partner->getProtein())));

	// Because, as for now, p27-Cks1 = Cks1-p27, the symetric test has to be done.
	bool testSymetricContains = complex->hasAsPartner(base) && ((partner != nullptr) == (partner != nullptr && complex->baseEqualsTo(partner->getProtein())));

	return testContains || testSymetricContains;
}

ProteinComplex* ProteinsContainer::getComplexForGlobalProtein(GlobalProtein* protein, std::shared_ptr<Protein> base, GlobalProtein* partner) const
{
	ProteinComplex* complex = nullptr;
	bool found = false;
	std::vector<ProteinComplex*> complexes = map_.at(protein);
	unsigned int size = complexes.size();
	for (unsigned int i = 0; !found && i < size; i++){
		if (complexEqualsTo(complexes.at(i), base, partner)){
			found = true;
			complex = complexes.at(i);
		}
	}
	std::cout << found << std::endl;
	return complex;
}

ProteinComplex* ProteinsContainer::getComplexForGlobalProtein(GlobalProtein* protein, GlobalProtein* base, GlobalProtein* partner) const
{
	ProteinComplex* complex = getComplexForGlobalProtein(protein, base->getProtein(), partner);
	return complex;
}

ProteinComplex* ProteinsContainer::getComplex(std::vector<std::shared_ptr<Protein>> base, std::vector<std::shared_ptr<Protein>> partner) const
{
	unsigned int psize = proteins_.size();
	unsigned int compsize;
	ProteinComplex* complex = nullptr;
	bool found = false;
	
	for(unsigned int i = 0; !found && i < psize; i++){
		std::vector<ProteinComplex*> complexes = map_.at(proteins_.at(i));
		compsize = complexes.size();
		for (unsigned int j = 0; !found && j < compsize; j++){
			ProteinComplex* comp = complexes.at(j);
			if ((comp->baseEqualsTo(base) && comp->hasAsPartner(partner)) || (comp->baseEqualsTo(partner) && comp->hasAsPartner(base))){
				found = true;
				complex = comp;
			}
		}
	}
	std::cout << found << std::endl;
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