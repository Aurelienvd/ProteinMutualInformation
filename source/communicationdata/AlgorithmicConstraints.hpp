#ifndef __ALGORITHMIC_CONSTRAINTS_HPP
#define __ALGORITHMIC_CONSTRAINTS_HPP

#include <string>

#include "Data.hpp"

class AlgorithmicConstraints: public Data {

	public:
		class ProteinConstraints;


	private:

		ProteinConstraints* input_;
		ProteinConstraints* channel_;
		ProteinConstraints* output_;
		int type_;

		void setProteinConstraints(ProteinConstraints* attr, std::string protein, int init, int final, float step);


	public:
		enum Information {bivariate = 1, trivariate = 2};
		
		AlgorithmicConstraints();
		~AlgorithmicConstraints();

		ProteinConstraints* getInput() const;
		ProteinConstraints* getOutput() const;
		ProteinConstraints* getChannel() const;
		int getMutualInformationType() const;

		void setInput(std::string protein, int init, int final, float step);
		void setOutput(std::string protein, int init, int final, float step);
		void setChannel(std::string protein, int init, int final, float step);
		void setMutualInformationType(int type);

		class ProteinConstraints {
			private:

				std::string protein_;
				int initial_value_;
				int final_value_;
				float step_;

				friend class AlgorithmicConstraints;

			public:
				ProteinConstraints() = default;

				std::string getProtein() const {return protein_;}
				int getInitialValue() const {return initial_value_;}
				int getFinalValue() const {return final_value_;}
				float getStep() const {return step_;}

		};
};

#endif /* __ALGORITHMIC_CONSTRAINTS_HPP */