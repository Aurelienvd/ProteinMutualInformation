
/**
 * An AlgorithmicConstraints defines the constraints that the information algorithms will have to respect.
 */

#ifndef __ALGORITHMIC_CONSTRAINTS_HPP
#define __ALGORITHMIC_CONSTRAINTS_HPP

#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include "../protein/Protein.hpp"
#include "../constants/constants.hpp"

#include "Data.hpp"

class AlgorithmicConstraints: public Data {


	public:
		class ProteinConstraints;

	typedef std::vector<std::shared_ptr<ProteinConstraints>> inputsconstraints;

	private:

		//-------------------------
		// Private data members
		//-------------------------
		//
		// input_
		//		The constraints of the input
		//
		// channel_
		//		The constraints of the channel
		//
		// output_
		//		The constraints of the output
		//
		// type_
		//		The type of the algorithm that will be executed
		//
		// inputs_
		//		The constraints of the inputs (for multivariate info)

		std::shared_ptr<ProteinConstraints> input_;
		std::shared_ptr<ProteinConstraints> channel_;
		std::shared_ptr<ProteinConstraints> output_;
		inputsconstraints inputs_;
		int type_;

		//-------------------------
		// Private member functions
		//-------------------------
		//
		// setProteinConstraints
		//		Set the constraints of a protein.

		void setProteinConstraints(std::shared_ptr<ProteinConstraints> attr, std::shared_ptr<Protein> protein_name, float init, float final, float step);


	public:

		enum Information {bivariate = 1, trivariate = 2};
		
		AlgorithmicConstraints();
		virtual ~AlgorithmicConstraints() = default;

		//--------------------------
		// Getters and Setters
		//--------------------------

		/**
		 * Get the constraints of the input protein.
		 *
		 * @return A ProteinConstraints pointer that contains the constraints for the input.
		 *
		 * @see ProteinConstraints
		 */

		std::shared_ptr<ProteinConstraints> getInput() const;

		/**
		 * Get the constraints of the input protein from the inputs vector.
		 *
		 * @param the index of the protein in the inputs vector.
		 *
		 * @return A ProteinsConstraints pointer that contains the constraints for the input.
		 *
		 * @see ProteinConstraints
		 */

		std::shared_ptr<ProteinConstraints> getInput(int index) const;

		/**
		 * Get the constraints of the output protein.
		 *
		 * @return A ProteinConstraints pointer that contains the constraints for the output.
		 *
		 * @see ProteinConstraints
		 */

		std::shared_ptr<ProteinConstraints> getOutput() const;

		/**
		 * Get the constraints of the channel protein.
		 *
		 * @return A ProteinConstraints pointer that contains the constraints for the channel.
		 *
		 * @see ProteinConstraints
		 */

		std::shared_ptr<ProteinConstraints> getChannel() const;

		/**
		 * Get the number of input proteins. (for multivariate info)
		 *
		 * @return the size of the inputs vector.
		 */

		unsigned int getNbInputs() const;

		/**
		 * Get the maximum size of the complexes which is the size of the inputs + the channel.
		 *
		 * The output is not taken into account here.
		 *
		 * @return the maximum size of the complexes.
		 */

		unsigned int getMaxComplexSize() const;

		/**
		 * Get the type of the algorithm that will be executed.
		 *
		 * @return A value defined in the enum.
		 *
		 * @see ProteinConstraints
		 */

		int getMutualInformationType() const;

		/**
		 * Set the constraints of the input protein.
		 *
		 * @param protein A std::shared_ptr to an instance of the Protein class
		 * @param init The required starting value of the protein concentration.
		 * @param final The required ending value of the protein concentration.
		 * @param step The required increment of the protein concentration.
		 *
		 * @see ProteinConstraints
		 */

		void setInput(std::shared_ptr<Protein> protein, float init, float final, float step);

		/**
		 * Add the constraints of one input protein. (for multivariate info)
		 *
		 * @param protein A std::shared_ptr to an instance of the Protein class
		 * @param init The required starting value of the protein concentration.
		 * @param final The required ending value of the protein concentration.
		 * @param step The required increment of the protein concentration.
		 *
		 * @see ProteinConstraints
		 */

		void addInput(std::shared_ptr<Protein> protein, float init, float final, float step);

		/**
		 * Resets inputs.
		 */

		void resetInputs();

		/**
		 * Set the constraints of the output protein.
		 *
		 * @param protein A std::shared_ptr to an instance of the Protein class
		 * @param init The required starting value of the protein concentration.
		 * @param final The required ending value of the protein concentration.
		 * @param step The required increment of the protein concentration.
		 *
		 * @see ProteinConstraints
		 */

		void setOutput(std::shared_ptr<Protein> protein, float init, float final, float step);

		/**
		 * Set the constraints of the channel protein.
		 *
		 * @param protein A std::shared_ptr to an instance of the Protein class
		 * @param init The required starting value of the protein concentration.
		 * @param final The required ending value of the protein concentration.
		 * @param step The required increment of the protein concentration.
		 *
		 * @see ProteinConstraints
		 */

		void setChannel(std::shared_ptr<Protein> protein, float init, float final, float step);

		/**
		 * Set the type of the algorithm that will be executed.
		 *
		 * @param type The required type of the algorithm. The possible values are the ones defined in the enum.
		 */

		void setMutualInformationType(int type);

		/**
		 * ProteinConstraints defines algorithmic constraints for one protein.
		 * It has to be noted that there are no setters nor constructors for this class.
		 * The only way to initialise a ProteinConstraints is by using the AlgorithmicConstraints class.
		 * Indeed, the AlgorithmicConstraints class is a friend of the ProteinConstraints class and as so,
		 * it has access to all the private fields of the class.
		 */

		class ProteinConstraints {
			private:

				std::shared_ptr<Protein> protein_;
				float initial_value_;
				float final_value_;
				float step_;

				
				friend class AlgorithmicConstraints;

			public:
				ProteinConstraints(): protein_(nullptr), initial_value_(0.0), final_value_(0.0), step_(0.0) {};

				/**
				 * Get the protein.
				 *
				 * @return A std::shared_ptr to a Protein instance.
				 */

				std::shared_ptr<Protein> getProtein() const {return protein_;}

				/**
				 * Get the starting value of the protein concentration.
				 *
				 * @return The starting value.
				 */

				float getInitialValue() const {return initial_value_;}

				/**
				 * Get the ending value of the protein concentration.
				 *
				 * @return The ending value.
				 */

				float getFinalValue() const {return final_value_;}

				/**
				 * Get the increment of the protein concentration.
				 *
				 * @return The increment value.
				 */

				float getStep() const {return step_;}

		};
};

std::ostream& operator<<( std::ostream &flux, AlgorithmicConstraints const& comp);
std::ostream& operator<<( std::ostream &flux, AlgorithmicConstraints::ProteinConstraints const& comp);

#endif /* __ALGORITHMIC_CONSTRAINTS_HPP */