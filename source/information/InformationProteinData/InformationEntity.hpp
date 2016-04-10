#ifndef __INFORMATION_ENTITY_HPP
#define __INFORMATION_ENTITY_HPP


#include <vector>
#include <string>
#include <cstddef>

#include "../../protein/GlobalProtein.hpp"
#include "../../protein/ProteinComplex.hpp"

/*
*** This class represents an information entity based on the Shannon's communication model. It has been adapted to proteins communication.
*/

class InformationEntity {

	private:

		GlobalProtein* entity_;
		std::vector<ProteinComplex*> related_complexes_;		// All the complexes containing the entity.
		int initial_value_;
		int final_value_;
		float step_;

	public:

		InformationEntity();

		GlobalProtein* getEntity() const;
		std::vector<ProteinComplex*> getRelatedComplexes() const;
		int getInitialValue() const;
		int getFinalValue() const;
		float getStep() const;

		void setEntity(GlobalProtein* protein);
		void addRelatedComplex(ProteinComplex* complex);
		void setInitialValue(int val);
		void setFinalValue(int val);
		void setStep(float step);

};

#endif /* __INFORMATION_ENTITY_HPP */