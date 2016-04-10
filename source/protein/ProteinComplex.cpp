#include "ProteinComplex.hpp"

ProteinComplex::ProteinComplex(ProteinsVector base): base_(base), concentration_(0), dissociation_constant_(0), base_size_(base.size()), partner_size_(0) {}

ProteinComplex::ProteinComplex(ProteinsVector base, ProteinsVector partner, double dissociation_constant): base_(base), binding_partner_(partner), 
							   dissociation_constant_(dissociation_constant_), concentration_(0), alias_(std::string()), base_size_(base.size()), partner_size_(partner.size()) {}


ProteinComplex::ProteinComplex(ProteinsVector base, ProteinsVector partner, std::string alias, double dissociation_constant): base_(base), binding_partner_(partner), 
							   dissociation_constant_(dissociation_constant_), alias_(alias), concentration_(0), base_size_(base.size()), partner_size_(partner.size()) {}


ProteinsVector ProteinComplex::getBase() const
{
	return base_;
}

ProteinsVector ProteinComplex::getPartner() const
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

unsigned int ProteinComplex::getBaseSize() const
{
	return base_size_;
}

unsigned int ProteinComplex::getPartnerSize() const
{
	return partner_size_;
}

void ProteinComplex::setConcentration(double concentration)
{
	concentration_ = concentration;
}

bool ProteinComplex::hasAsPartner(ProteinsVector partner) const
{
	return binding_partner_ == partner;
}

bool ProteinComplex::hasProteinInBase(std::shared_ptr<Protein> protein) const
{
	bool found = false;
	unsigned int size = base_.size();
	for (unsigned int i = 0; !found && i < size; i++){
		if (*base_.at(i) == *protein){
			found = true;
		}
	}
	return found;
}

bool ProteinComplex::baseEqualsTo(std::string base) const
{
	return base_ == base;
}

bool ProteinComplex::baseSizeEqualsTo(unsigned int size) const
{
	return base_size_ == size;
}

bool ProteinCOmplex::partnerSizeEqualsTo(unsigned int size) const
{
	return partner_size_ == size;
}