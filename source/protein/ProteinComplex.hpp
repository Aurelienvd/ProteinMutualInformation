#ifndef __PROTEIN_COMPLEX_HPP
#define __PROTEIN_COMPLEX_HPP

#include <string>


class ProteinComplex {

private:

	std::string base_;			// Represents the input in the Shannon's Communication Model.
	std::string binding_partner_;	// Represents the output.
	std::string alias_;				// Allows the client to name the complex if its base is to complicated (e.g. Skp2-Cdk2-Cks1-p27 can be renamed as 'Complex 1' or so) .
	double concentration_;
	double dissociation_constant_;

public:

	ProteinComplex(std::string base, std::string partner, double dissociation_constant);
	ProteinComplex(std::string base, std::string partner, std::string alias, double dissociation_constant);

	std::string getBase() const;		// If alias is defined, getBase returns the alias instead of the base.
	std::string getPartner() const;
	double getConcentration() const;
	double getDissociationConstant() const;
	void setConcentration(double concentration);

	bool hasAsPartner(std::string partner) const;
	bool hasProteinInBase(std::string protein) const;
	bool baseEqualsTo(std::string base) const;

};

#endif /* __PROTEIN_COMPLEX_HPP */