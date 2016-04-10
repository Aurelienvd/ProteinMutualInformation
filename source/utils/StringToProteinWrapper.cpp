#include "StringToProteinWrapper.hpp"
#include "StringSplitter.hpp"


std::shared_ptr<Protein> wrapString(std::string protein_name)
{
	auto ptr = std::make_shared<Protein>(protein_name);
	return ptr;
}

std::vector<std::vector<std::shared_ptr<Protein>>> wrapStringVector(std::vector<std::string> vector)
{
	std::vector<std::vector<std::shared_ptr<Protein>>> complexes;
	for (std::string complex : vector){
		std::vector<std::shared_ptr<Protein>> proteins;
		for (std::string protein_name : splitString(complex, PROTSEPARATOR)){
			proteins.push_back(wrapString(protein_name));
		}
		complexes.push_back(proteins);
	}
	return complexes;
}