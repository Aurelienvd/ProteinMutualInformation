#include "Protein.hpp"

Protein::Protein(std::string name): protein_name_(name) {}

std::string Protein::getProteinName() const
{
	return protein_name_;
}

bool operator==(Protein const& prot1, Protein const& prot2)
{
	return prot1.getProteinName() == prot2.getProteinName();
}