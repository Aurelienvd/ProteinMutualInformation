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

	public:

		class Range;


	private:

		GlobalProtein* protein_;
		std::vector<ProteinComplex*> related_complexes_;		// All the complexes containing the entity.
		Range* range_;

	public:

		InformationEntity();
		~InformationEntity();

		GlobalProtein* getProtein() const;
		std::vector<ProteinComplex*> getRelatedComplexes() const;
		std::vector<double> getRange() const;
		float getRangeMidValue() const;
		double getProteinConcentration() const;

		void setEntity(GlobalProtein* protein);
		void addRelatedComplex(ProteinComplex* complex);
		void setInitialValue(int val);
		void setFinalValue(int val);
		void setStep(float step);
		void setProteinConcentration(double concent);

		class Range{

			private:

				int initial_value_;
				int final_value_;
				float step_;

				friend class InformationEntity;

			public:

				std::vector<double> getRange() const;
				float getRangeMidValue() const;

				void setInitialValue(int value) {initial_value_ = value;}
				void setFinalValue(int value) {final_value_ = value;}
				void setStep(float step) {step_ = step;}

		};

};

#endif /* __INFORMATION_ENTITY_HPP */