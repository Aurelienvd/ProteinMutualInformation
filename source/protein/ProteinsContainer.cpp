#include "ProteinsContainer.hpp"
#include <iostream>

ProteinsContainer::ProteinsContainer(): proteins_(), map_() {}


ProteinsContainer::ProteinsContainer(std::shared_ptr<GlobalProtein> protein)
{
	proteins_.push_back(protein);
	map_.insert(proteins_pair(protein, std::vector<std::shared_ptr<ProteinComplex>>()));
}

ProteinsContainer::ProteinsContainer(std::vector<std::shared_ptr<GlobalProtein>> proteins): proteins_(proteins)
{
	for (std::shared_ptr<GlobalProtein> protein : proteins){
		map_.insert(proteins_pair(protein, std::vector<std::shared_ptr<ProteinComplex>>()));
	}
}

std::shared_ptr<ProteinComplex> ProteinsContainer::getUnfoundComplex() const
{
	std::vector<std::shared_ptr<Protein>> base;
	for (int i = 0; i < infoconfig::kBIOneSidedComplexSize; i++){
		base.push_back(std::make_shared<Protein>(error_indicator::kUnfoundComplexName));
	}

	return std::make_shared<ProteinComplex>(base);
}

std::shared_ptr<GlobalProtein> ProteinsContainer::getProtein(std::shared_ptr<Protein> name) const
{
	std::shared_ptr<GlobalProtein> protein = nullptr;
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

std::vector<std::shared_ptr<GlobalProtein>> ProteinsContainer::getProteins() const
{
	return proteins_;
}

bool ProteinsContainer::complexEqualsTo(std::shared_ptr<ProteinComplex> complex, std::shared_ptr<Protein> base, std::shared_ptr<GlobalProtein> partner) const
{
	bool testContains = complex->baseEqualsTo(base) && ((partner != nullptr) == (partner != nullptr && complex->hasAsPartner(partner->getProtein())));

	// Because, as for now, p27-Cks1 = Cks1-p27, the symetric test has to be done.
	bool testSymetricContains = complex->hasAsPartner(base) && ((partner != nullptr) == (partner != nullptr && complex->baseEqualsTo(partner->getProtein())));

	return testContains || testSymetricContains;
}

std::shared_ptr<ProteinComplex> ProteinsContainer::getComplexForGlobalProtein(std::shared_ptr<GlobalProtein> protein, std::shared_ptr<Protein> base, std::shared_ptr<GlobalProtein> partner) const
{
	std::shared_ptr<ProteinComplex> complex = nullptr;
	bool found = false;
	std::vector<std::shared_ptr<ProteinComplex>> complexes = map_.at(protein);
	unsigned int size = complexes.size();
	for (unsigned int i = 0; !found && i < size; i++){
		if (complexEqualsTo(complexes.at(i), base, partner)){
			found = true;
			complex = complexes.at(i);
		}
	}

	complex = (complex == nullptr ? getUnfoundComplex() : complex);

	return complex;
}

std::shared_ptr<ProteinComplex> ProteinsContainer::getComplexForGlobalProtein(std::shared_ptr<GlobalProtein> protein, std::shared_ptr<GlobalProtein> base, std::shared_ptr<GlobalProtein> partner) const
{	
	std::shared_ptr<ProteinComplex> complex = nullptr;
	if (base == nullptr){
		complex = getUnfoundComplex();
	} else{
		complex = getComplexForGlobalProtein(protein, base->getProtein(), partner);
	}
	return complex;
}

std::shared_ptr<ProteinComplex> ProteinsContainer::getComplex(std::vector<std::shared_ptr<Protein>> base, std::vector<std::shared_ptr<Protein>> partner) const
{
	unsigned int psize = proteins_.size();
	unsigned int compsize;
	std::shared_ptr<ProteinComplex> complex = nullptr;
	bool found = false;
	
	for(unsigned int i = 0; !found && i < psize; i++){
		std::vector<std::shared_ptr<ProteinComplex>> complexes = map_.at(proteins_.at(i));
		compsize = complexes.size();
		for (unsigned int j = 0; !found && j < compsize; j++){
			std::shared_ptr<ProteinComplex> comp = complexes.at(j);
			if ((comp->baseEqualsTo(base) && comp->hasAsPartner(partner)) || (comp->baseEqualsTo(partner) && comp->hasAsPartner(base))){
				found = true;
				complex = comp;
			}
		}
	}

	complex = (complex == nullptr ? getUnfoundComplex() : complex);

	return complex;
}

std::vector<std::shared_ptr<ProteinComplex>> ProteinsContainer::getComplexesForGlobalProtein(std::shared_ptr<GlobalProtein> protein) const
{
	return map_.at(protein);
}

void ProteinsContainer::addProteinComplexForProtein(std::shared_ptr<GlobalProtein> protein, std::shared_ptr<ProteinComplex> complex)
{
	std::vector<std::shared_ptr<ProteinComplex>> complexes = map_.at(protein);
	complexes.push_back(complex);
	map_[protein] = complexes;
}

std::vector<std::shared_ptr<ProteinComplex>> ProteinsContainer::getComplexesForGlobalProtein(std::shared_ptr<GlobalProtein> protein, unsigned int min, unsigned int max)
{
	auto all_complexes = getComplexesForGlobalProtein(protein);
	std::vector<std::shared_ptr<ProteinComplex>> complexes;
	for (unsigned int i = min; i < max; i++){
		for (std::shared_ptr<ProteinComplex> comp : all_complexes){
			if (comp->getComplexSize() == min){
				complexes.push_back(comp);
			}
		}
	}

	return complexes;
}