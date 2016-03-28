#ifndef __PROTEINS_CONTAINER_BUILDER_HPP
#define __PROTEINS_CONTAINER_BUILDER_HPP

#include "ProteinsContainer.hpp"
#include "../communicationdata/ConcreteStream.hpp"
#include <cstddef>


class ProteinsContainerBuilder {

private:

	ProteinsContainer* proteins_container_;
	std::vector<GlobalProtein*> global_proteins_;
	std::vector<ProteinComplex*> protein_complexes_;
	std::vector<std::string> complexes_;
	std::vector<std::string> partners_;
	std::vector<double> constants_;

	void addGlobalProteinsFromComplex(std::string complex);
	void singletonAdd(std::string protein);
	void addComplex(GlobalProtein* protein);

public:

	ProteinsContainerBuilder();
	~ProteinsContainerBuilder();

	void updateData(ConcreteStream* data);
	void buildGlobalProtein();
	void buildProteinComplexes();
	void buildProteinsContainer();
	ProteinsContainer* getProteinsContainer() const;




};

#endif /* __PROTEINS_CONTAINER_BUILDER_HPP */