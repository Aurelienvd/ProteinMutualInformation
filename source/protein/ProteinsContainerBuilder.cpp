#include "ProteinsContainerBuilder.hpp"
#include "../utils/StringToProteinWrapper.hpp"


ProteinsContainerBuilder::ProteinsContainerBuilder(): proteins_container_(nullptr) {}


void ProteinsContainerBuilder::updateData(ConcreteStream* data)
{
	complexes_ = wrapStringVector(data->getComplexes());
	partners_ = wrapStringVector(data->getPartners());
	constants_ = data->getConstantsAsDoubleVector();
}

void ProteinsContainerBuilder::singletonAdd(std::shared_ptr<Protein> protein)
{
	bool is_present = false;
	for (GlobalProtein* global : global_proteins_){
		if (global->equalsTo(protein)){
			is_present = true;
		}
	}
	if (!is_present){
		global_proteins_.push_back(new GlobalProtein(protein));
	}
}

void ProteinsContainerBuilder::addGlobalProteinsFromComplex(std::vector<std::shared_ptr<Protein>> complex)
{
	for (std::shared_ptr<Protein> protein : complex){
		singletonAdd(protein);				// This doesn't add a singleton object, it just adds the protein only if no other 
											//protein with the same name is present. didn't know how to name this....
	}
}

void ProteinsContainerBuilder::addComplexVersionOfGlobalProtein(GlobalProtein* protein)
{
	std::vector<std::shared_ptr<Protein>> base;
	base.push_back(protein->getProtein());
	proteins_container_->addProteinComplexForProtein(protein, new ProteinComplex(base));
}

void ProteinsContainerBuilder::addComplex(GlobalProtein* protein)
{
	for (ProteinComplex* complex : protein_complexes_){
		if (complex->hasProteinInBase(protein->getProtein()) || complex->hasProteinInPartner(protein->getProtein())){
			proteins_container_->addProteinComplexForProtein(protein, complex);
		}
	}
}

void ProteinsContainerBuilder::buildGlobalProtein()
{
	for (std::vector<std::shared_ptr<Protein>> complex : complexes_){
		addGlobalProteinsFromComplex(complex);
	}

	for (std::vector<std::shared_ptr<Protein>> partner : partners_){
		addGlobalProteinsFromComplex(partner);
	}
}

void ProteinsContainerBuilder::buildProteinComplexes()
{
	std::size_t size = complexes_.size();
	for (unsigned int i = 0; i < size; i++){
		protein_complexes_.push_back(new ProteinComplex(complexes_.at(i), partners_.at(i), constants_.at(i)));
	}
}

void ProteinsContainerBuilder::buildProteinsContainer()
{
	proteins_container_ = new ProteinsContainer(global_proteins_);
	for (GlobalProtein* protein : global_proteins_){
		addComplexVersionOfGlobalProtein(protein);
		addComplex(protein);
	}

}

ProteinsContainer* ProteinsContainerBuilder::getProteinsContainer() const
{
	return proteins_container_;
}