#ifndef __PROTEINS_CONTAINER_HPP
#define __PROTEINS_CONTAINER_HPP


#include "GlobalProtein.hpp"
#include "ProteinComplex.hpp"
#include <vector>
#include <map>

class ProteinsContainer {

	typedef std::map<GlobalProtein*, std::vector<ProteinComplex*>> proteins_map;			// This map binds a protein with all the complexes that contains this protein.
	typedef std::pair<GlobalProtein*, std::vector<ProteinComplex*>> proteins_pair;

private:

	std::vector<GlobalProtein*> proteins_;
	proteins_map map_;

public:

	ProteinsContainer(std::vector<GlobalProtein*> proteins);


};

#endif /* __PROTEINS_CONTAINER_HPP */