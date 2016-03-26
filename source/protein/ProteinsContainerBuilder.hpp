#ifndef __PROTEINS_CONTAINER_BUILDER_HPP
#define __PROTEINS_CONTAINER_BUILDER_HPP

#include "ProteinsContainer.hpp"


class ProteinsContainerBuilder {

private:

	ProteinsContainer* proteins_container_;
	std::vector<GlobalProtein*> global_proteins_;
	std::vector<ProteinComplex*> protein_complexes_;
	std::vector<std::string> proteins_;
	std::vector<std::string> partners_;
	std::vector<std::string> constants_;

public:

	void updateData(std::vector<std::string> proteins ,std::vector<std::string> partners, std::vector<std::string> constants);
	void buildGlobalProtein();
	void buildProteinComplexes();
	void buildProteinsContainer();
	ProteinsContainer* getProteinsContainer() const;




};

#endif /* __PROTEINS_CONTAINER_BUILDER_HPP */