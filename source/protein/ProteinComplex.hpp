#ifndef __PROTEIN_COMPLEX_HPP
#define __PROTEIN_COMPLEX_HPP

#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include "Protein.hpp"
#include <memory>
#include <iostream>

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

	bool hasItemInVector(ProteinsVector vector, std::shared_ptr<Protein> item) const;
	bool proteinsVectorEqual(ProteinsVector v1, ProteinsVector v2) const;

public:

	ProteinComplex(ProteinsVector base);		// A complex containing only one Protein.
	ProteinComplex(ProteinsVector base, ProteinsVector partner, double dissociation_constant);
	ProteinComplex(ProteinsVector base, ProteinsVector partner, std::string alias, double dissociation_constant);

	ProteinsVector getBase() const;
	ProteinsVector getPartner() const;
	double getConcentration() const;
	double getDissociationConstant() const;
	unsigned int getBaseSize() const;
	unsigned int getPartnerSize() const;
	unsigned int getComplexSize() const;
	void setConcentration(double concentration);

	bool hasAsPartner(std::shared_ptr<Protein> partner) const;
	bool hasAsPartner(ProteinsVector partner) const;
	bool hasProteinInPartner(std::shared_ptr<Protein> protein) const;
	bool hasProteinInBase(std::shared_ptr<Protein> protein) const;
	bool baseEqualsTo(ProteinsVector base) const;
	bool baseEqualsTo(std::shared_ptr<Protein> base) const;
	bool baseSizeEqualsTo(unsigned int size) const;
	bool partnerSizeEqualsTo(unsigned int size) const;

};

std::ostream& operator<<( std::ostream &flux, ProteinComplex const& comp);


#endif /* __PROTEIN_COMPLEX_HPP */