#ifndef __PROTEINS_CONTAINER_BUILDER_HPP
#define __PROTEINS_CONTAINER_BUILDER_HPP

#include "ProteinsContainer.hpp"
#include "../communicationdata/ConcreteStream.hpp"
#include <cstddef>
#include <memory>


class ProteinsContainerBuilder {

	typedef std::vector<std::vector<std::shared_ptr<Protein>>> ComplexesVector;

private:

	std::shared_ptr<ProteinsContainer> proteins_container_;
	std::vector<std::shared_ptr<GlobalProtein>> global_proteins_;
	std::vector<std::shared_ptr<ProteinComplex>> protein_complexes_;
	ComplexesVector complexes_;
	ComplexesVector partners_;
	std::vector<double> constants_;

	void addGlobalProteinsFromComplex(std::vector<std::shared_ptr<Protein>> complex);
	void addComplexVersionOfGlobalProtein(std::shared_ptr<GlobalProtein> protein);
	void singletonAdd(std::shared_ptr<Protein> protein);
	void addComplex(std::shared_ptr<GlobalProtein> protein);

public:

	ProteinsContainerBuilder();

	void updateData(std::shared_ptr<ConcreteStream> data);
	void buildGlobalProtein();
	void buildProteinComplexes();
	void buildProteinsContainer();
	std::shared_ptr<ProteinsContainer> getProteinsContainer() const;




};

#endif /* __PROTEINS_CONTAINER_BUILDER_HPP */