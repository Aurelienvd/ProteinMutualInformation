#ifndef __PROTEIN_HPP
#define __PROTEIN_HPP


#include <string>

class Protein {

	private:

		std::string protein_name_;

	public:

		Protein(std::string name);
		std::string getProteinName() const;
};

bool operator==(Protein const& prot1, Protein const& prot2);

#endif /* __PROTEIN_HPP  */