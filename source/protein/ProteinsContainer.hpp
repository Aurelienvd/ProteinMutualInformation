#ifndef __PROTEINS_CONTAINER_HPP
#define __PROTEINS_CONTAINER_HPP


#include "GlobalProtein.hpp"
#include "ProteinComplex.hpp"
#include <vector>
#include <map>
#include <cstddef>
#include <memory>
#include "../constants/constants.hpp"

class ProteinsContainer {

	typedef std::map<std::shared_ptr<GlobalProtein>, std::vector<std::shared_ptr<ProteinComplex>>> proteins_map;			// This map binds a protein with all the complexes that contains this protein.
	typedef std::pair<std::shared_ptr<GlobalProtein>, std::vector<std::shared_ptr<ProteinComplex>>> proteins_pair;

private:

	std::vector<std::shared_ptr<GlobalProtein>> proteins_;
	proteins_map map_;
	
	void addProteinComplexForProtein(std::shared_ptr<GlobalProtein> protein, std::shared_ptr<ProteinComplex> complex);
	bool complexEqualsTo(std::shared_ptr<ProteinComplex> complex, std::shared_ptr<Protein> base, std::shared_ptr<GlobalProtein> partner) const;
	std::shared_ptr<ProteinComplex> getUnfoundComplex() const;

	friend class ProteinsContainerBuilder;

public:

	ProteinsContainer();

	ProteinsContainer(std::shared_ptr<GlobalProtein> protein);
	ProteinsContainer(std::vector<std::shared_ptr<GlobalProtein>> proteins);
	
	std::vector<std::shared_ptr<GlobalProtein>> getProteins() const;
	
	std::shared_ptr<GlobalProtein> getProtein(std::shared_ptr<Protein> name) const;
	
	std::vector<std::shared_ptr<ProteinComplex>> getComplexesForGlobalProtein(std::shared_ptr<GlobalProtein> protein) const;
	
	std::shared_ptr<ProteinComplex> getComplexForGlobalProtein(std::shared_ptr<GlobalProtein> protein, std::shared_ptr<GlobalProtein> base, std::shared_ptr<GlobalProtein> partner = nullptr) const;
	
	std::shared_ptr<ProteinComplex> getComplexForGlobalProtein(std::shared_ptr<GlobalProtein> protein, std::shared_ptr<Protein> base, std::shared_ptr<GlobalProtein> partner = nullptr) const;
	
	std::shared_ptr<ProteinComplex> getComplex(std::vector<std::shared_ptr<Protein>> base, std::vector<std::shared_ptr<Protein>> partner) const;
	
	std::vector<std::shared_ptr<ProteinComplex>> getComplexesForGlobalProtein(std::shared_ptr<GlobalProtein>, unsigned int min, unsigned int max);

};

#endif /* __PROTEINS_CONTAINER_HPP */