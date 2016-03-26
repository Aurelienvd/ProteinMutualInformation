#ifndef __TOTAL_PROTEIN_CONCENTRATION_HPP
#define __TOTAL_PROTEIN_CONCENTRATION_HPP

#include <string>


/*
***  This object represents the total amount of a protein presents in the whole system. Given the protein p27, if there are 4 complexes involving a p27 protein,
***	 an instance of this class, with the protein_ set as P27, will give the total concentration of p27.
***  This is especially useful for the mutual information algorithm because it uses mainly the total concentration of a protein to compute I(x,y).
*/


class TotalProteinConcentration {

private:

	std::string protein_;
	double concentration_;

};

#endif /* __TOTAL_PROTEIN_CONCENTRATION_HPP */