#ifndef __PROTEIN_COMPLEX_HPP
#define __PROTEIN_COMPLEX_HPP

#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include "Protein.hpp"

class ProteinComplex {

private:

	std::vector<Protein*> base_;			// Represents the input in the Shannon's Communication Model.
	std::vector<Protein*> binding_partner_;	// Represents the output.
	std::string alias_;				// Allows the client to name the complex if its base is to complicated (e.g. Skp2-Cdk2-Cks1-p27 can be renamed as 'Complex 1' or so) .
	double concentration_;
	double dissociation_constant_;
	unsigned int base_size_;
	unsigned int binding_partner_size_;

public:

	ProteinComplex(Protein* base);		// A complex containing only one Protein.
	ProteinComplex(std::vector<Protein*> base, std::vector<Protein*> partner, double dissociation_constant);
	ProteinComplex(std::vector<Protein*> base, std::vector<Protein*> partner, std::string alias, double dissociation_constant);

	std::vector<Protein*> getBase() const;
	std::vector<Protein*> getPartner() const;
	double getConcentration() const;
	double getDissociationConstant() const;
	unsigned int getBaseSize() const;
	unsigned int getPartnerSize() const;
	void setConcentration(double concentration);

	bool hasAsPartner(std::vector<Protein*> partner) const;
	bool hasProteinInBase(Protein* protein) const;
	bool baseEqualsTo(std::vector<Protein*> base) const;
	bool baseSizeEqualsTo(unsigned int size) const;
	bool partnerSizeEqualsTo(unsigned int size) const;

};

#endif /* __PROTEIN_COMPLEX_HPP */