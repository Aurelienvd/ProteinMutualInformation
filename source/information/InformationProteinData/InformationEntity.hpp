#ifndef __INFORMATION_ENTITY_HPP
#define __INFORMATION_ENTITY_HPP


#include <vector>
#include <string>

#include "../../protein/GlobalProtein.hpp"
#include "../../protein/ProteinComplex.hpp"

/*
*** This class represents an information entity based on the Shannon's communication model. It has been adapted to proteins communication.
*/

class InformationEntity {

	private:

		GlobalProtein* entity_;
		std::vector<ProteinComplex*> related_complexes_;		// All the complexes containing the entity.

	public:

		InformationEntity(GlobalProtein* protein);

		GlobalProtein* getEntity() const;
		std::vector<ProteinComplex*> getRelatedComplexes() const;

		void addRelatedComplex(ProteinComplex* complex);

};

#endif /* __INFORMATION_ENTITY_HPP */