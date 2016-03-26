#include "ProteinComplex.hpp"

ProteinComplex::ProteinComplex(std::string base, std::string partner, double dissociation_constant): base_(base), binding_partner_(partner), 
							   dissociation_constant_(dissociation_constant_), concentration_(0), alias_(std::string()) {}


ProteinComplex::ProteinComplex(std::string base, std::string partner, std::string alias, double dissociation_constant): base_(base), binding_partner_(partner), 
							   dissociation_constant_(dissociation_constant_), alias_(alias), concentration_(0) {}


std::string ProteinComplex::getBase() const
{
	if (!alias_.empty()){
		return alias_;
	}
	return base_;
}

std::string ProteinComplex::getPartner() const
{
	return binding_partner_;
}

double ProteinComplex::getConcentration() const
{
	return concentration_;
}

double ProteinComplex::getDissociationConstant() const
{
	return dissociation_constant_;
}

void ProteinComplex::setConcentration(double concentration)
{
	concentration_ = concentration;
}

bool ProteinComplex::hasAsPartner(std::string partner) const
{
	return binding_partner_ == partner;
}

bool ProteinComplex::hasProteinInBase(std::string protein) const
{
	std::string::size_type pos = base_.find(protein);
	return (pos != std::string::npos);
}