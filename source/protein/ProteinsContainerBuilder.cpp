#include "ProteinsContainerBuilder.hpp"


void ProteinsContainerBuilder::updateData(ConcreteStream* data)
{
	complexes_ = data->getComplexes();
	partners_ = data->getPartners();
	constants_ = data->getConstants();
}

void ProteinsContainerBuilder::singletonAdd(std::string protein)
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

void ProteinsContainerBuilder::addGlobalProteinsFromComplex(std::string complex)
{
	std::vector<std::string> proteins = ConcreteStream::splitComplex(complex);
	for (std::string protein : proteins){
		singletonAdd(protein);				// This doesn't add a singleton object, it just adds the protein only if no other 
											//protein with the same name is present. didn't know how to name this....
	}
}

void ProteinsContainerBuilder::buildGlobalProtein()
{
	for (std::string complex : complexes_){
		addGlobalProteinsFromComplex(complex);
	}

	for (std::string partner : partners_){
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

}

ProteinsContainer* ProteinsContainerBuilder::getProteinsContainer() const
{
	return proteins_container_;
}