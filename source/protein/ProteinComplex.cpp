#include "ProteinComplex.hpp"

ProteinComplex::ProteinComplex(ProteinsVector base): base_(base), concentration_(0), dissociation_constant_(0), base_size_(base.size()), binding_partner_size_(0) {}

ProteinComplex::ProteinComplex(ProteinsVector base, ProteinsVector partner, double dissociation_constant): base_(base), binding_partner_(partner), 
							   dissociation_constant_(dissociation_constant), concentration_(0), alias_(std::string()), base_size_(base.size()), binding_partner_size_(partner.size()) {}


ProteinComplex::ProteinComplex(ProteinsVector base, ProteinsVector partner, std::string alias, double dissociation_constant): base_(base), binding_partner_(partner), 
							   dissociation_constant_(dissociation_constant), alias_(alias), concentration_(0), base_size_(base.size()), binding_partner_size_(partner.size()) {}


std::vector<std::shared_ptr<Protein>> ProteinComplex::getBase() const
{
	return base_;
}

std::vector<std::shared_ptr<Protein>> ProteinComplex::getPartner() const
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
	return binding_partner_size_;
}

void ProteinComplex::setConcentration(double concentration)
{
	concentration_ = concentration;
}

bool ProteinComplex::hasAsPartner(std::shared_ptr<Protein> partner) const
{
	return ((binding_partner_.size() == 1) && (*binding_partner_.at(0) == *partner));
}

bool ProteinComplex::hasAsPartner(ProteinsVector partner) const
{
	return binding_partner_ == partner;
}

bool ProteinComplex::hasItemInVector(ProteinsVector vector, std::shared_ptr<Protein> item) const
{
	bool found = false;
	unsigned int size = vector.size();
	for (unsigned int i = 0; !found && i < size; i++){
		if (*vector.at(i) == *item){
			found = true;
		}
	}
	return found;
}

bool ProteinComplex::hasProteinInPartner(std::shared_ptr<Protein> protein) const
{
	return hasItemInVector(base_, protein);
}

bool ProteinComplex::hasProteinInBase(std::shared_ptr<Protein> protein) const
{
	return hasItemInVector(binding_partner_, protein);
}

bool ProteinComplex::baseEqualsTo(std::shared_ptr<Protein> base) const
{
	return ((base_.size() == 1) && (*base_.at(0) == *base));
}

bool ProteinComplex::baseEqualsTo(ProteinsVector base) const
{
	return base_ == base;
}

bool ProteinComplex::baseSizeEqualsTo(unsigned int size) const
{
	return base_size_ == size;
}

bool ProteinComplex::partnerSizeEqualsTo(unsigned int size) const
{
	return binding_partner_size_ == size;
}