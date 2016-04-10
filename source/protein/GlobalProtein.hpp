#ifndef __GLOBAL_PROTEIN_HPP
#define __GLOBAL_PROTEIN_HPP


#include "Protein.hpp"
#include <memory>


/*
***  This object represents the total amount of a protein presents in the whole system. Given the protein p27, if there are 4 complexes involving a p27 protein,
***	 an instance of this class, with the protein_ set as P27, will give the total concentration of p27.
***  This is especially useful for the mutual information algorithm because it uses mainly the total concentration of a protein to compute I(x,y).
*/


class GlobalProtein {

private:

	std::shared_ptr<Protein> protein_;
	double total_concentration_;

public:

	GlobalProtein(std::shared_ptr<Protein> protein);

	double getTotalConcentration() const;
	std::shared_ptr<Protein> getProtein() const;
	void setTotalConcentration(double concentration);

	bool equalsTo(std::shared_ptr<Protein> protein) const;

};

#endif /* __GLOBAL_PROTEIN_HPP */