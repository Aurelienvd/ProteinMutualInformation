#ifndef __PROTEINS_CONTAINER_BUILDER_HPP
#define __PROTEINS_CONTAINER_BUILDER_HPP

#include "ProteinsContainer.hpp"
#include "../communicationdata/ConcreteStream.hpp"
#include "../utils/StringToProteinWrapper.hpp"
#include <cstddef>
#include <memory>


class ProteinsContainerBuilder {

	typedef std::vector<std::vector<std::shared_ptr<Protein>>> ComplexesVector;

private:

	ProteinsContainer* proteins_container_;
	std::vector<GlobalProtein*> global_proteins_;
	std::vector<ProteinComplex*> protein_complexes_;
	ComplexesVector complexes_;
	ComplexesVector partners_;
	std::vector<double> constants_;

	void addGlobalProteinsFromComplex(std::vector<std::shared_ptr<Protein>> complex);
	void addComplexVersionOfGlobalProtein(GlobalProtein* protein);
	void singletonAdd(std::shared_ptr<Protein> protein);
	void addComplex(GlobalProtein* protein);

public:

	ProteinsContainerBuilder();

	void updateData(ConcreteStream* data);
	void buildGlobalProtein();
	void buildProteinComplexes();
	void buildProteinsContainer();
	ProteinsContainer* getProteinsContainer() const;




};

#endif /* __PROTEINS_CONTAINER_BUILDER_HPP */