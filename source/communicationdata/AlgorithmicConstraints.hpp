#ifndef __ALGORITHMIC_CONSTRAINTS_HPP
#define __ALGORITHMIC_CONSTRAINTS_HPP

#include <cstddef>

#include "Data.hpp"
#include "../protein/GlobalProtein.hpp"		// Only for bivariate, this will change when the trivariate is handled.

class AlgorithmicConstraints: public Data {

	public:
		class ProteinConstraints;


	private:

		ProteinConstraints* input_;
		ProteinConstraints* channel_;
		ProteinConstraints* output_;
		int type_;

		void setProteinConstraints(ProteinConstraints* attr, GlobalProtein* protein, int init, int final, float step);


	public:
		enum Information {bivariate = 1, trivariate = 2};
		
		AlgorithmicConstraints();
		~AlgorithmicConstraints();

		ProteinConstraints* getInput() const;
		ProteinConstraints* getOutput() const;
		ProteinConstraints* getChannel() const;
		int getMutualInformationType() const;

		void setInput(GlobalProtein* protein, int init, int final, float step);
		void setOutput(GlobalProtein* protein, int init, int final, float step);
		void setChannel(GlobalProtein* protein, int init, int final, float step);
		void setMutualInformationType(int type);

		class ProteinConstraints {
			private:

				GlobalProtein* protein_;
				int initial_value_;
				int final_value_;
				float step_;

				friend class AlgorithmicConstraints;

			public:
				ProteinConstraints(): protein_(nullptr) {}

				GlobalProtein* getProtein() const {return protein_;}
				int getInitialValue() const {return initial_value_;}
				int getFinalValue() const {return final_value_;}
				float getStep() const {return step_;}

		};
};

#endif /* __ALGORITHMIC_CONSTRAINTS_HPP */