#ifndef __PROTEIN_COMPLEX_HPP
#define __PROTEIN_COMPLEX_HPP

#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include "Protein.hpp"
#include <memory>

class ProteinComplex {

	typedef std::vector<std::shared_ptr<Protein>> ProteinsVector;

private:

	ProteinsVector base_;			// Represents the input in the Shannon's Communication Model.
	ProteinsVector binding_partner_;	// Represents the output.
	std::string alias_;				// Allows the client to name the complex if its base is to complicated (e.g. Skp2-Cdk2-Cks1-p27 can be renamed as 'Complex 1' or so) .
	double concentration_;
	double dissociation_constant_;
	unsigned int base_size_;
	unsigned int binding_partner_size_;

public:

	ProteinComplex(std::shared_ptr<Protein> base);		// A complex containing only one Protein.
	ProteinComplex(ProteinsVector base, ProteinsVector partner, double dissociation_constant);
	ProteinComplex(ProteinsVector base, ProteinsVector partner, std::string alias, double dissociation_constant);

	ProteinsVector getBase() const;
	ProteinsVector getPartner() const;
	double getConcentration() const;
	double getDissociationConstant() const;
	unsigned int getBaseSize() const;
	unsigned int getPartnerSize() const;
	void setConcentration(double concentration);

	bool hasAsPartner(ProteinsVector partner) const;
	bool hasProteinInBase(std::shared_ptr<Protein> protein) const;
	bool baseEqualsTo(ProteinsVector base) const;
	bool baseSizeEqualsTo(unsigned int size) const;
	bool partnerSizeEqualsTo(unsigned int size) const;

};

#endif /* __PROTEIN_COMPLEX_HPP */