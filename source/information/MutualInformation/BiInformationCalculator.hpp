
/**
 * This class computes the mutual information passed through the communication system.
 * This is a version specific to a bivariate system.
 */

#ifndef __BINFORMATION_CALCULATOR_HPP
#define __BINFORMATION_CALCULATOR_HPP


#include <cmath>
#include <vector>

class BiInformationCalculator {


	private:

		//-------------------------
		// Private data members
		//-------------------------
		//
		// mutual_information
		//		The mutual information passed through the system.
		//
		// input_entropy
		//		The entropy of the input.
		//
		// output_entropy
		//		The entropy of the ouput.
		//
		// join_entropy
		//		The join entropy of the system.
		//
		// denominator
		//		A private data used only for computation purpose.
		//
		// concentrations
		//		Concentrations of the input, ouput and channel.

		double mutual_information;
		double input_entropy;
		double output_entropy;
		double join_entropy;
		double denominator;
		std::vector<double> concentrations;

		//-----------------------------
		// Private member functions
		//-----------------------------
		//
		// calculateDenominator
		//		Calculate the denominator of a defined fraction.
		//
		// findInputEntropy
		//		Compute the entropy of the input.
		//
		// findOutputEntropy
		//		Compute the entropy of the ouput.
		//
		// calculateJoinEntropy
		//		Calculate the join entropy of the system.
		//
		// calculateEntropies
		//		Call findOutputEntropy and findInputEntropy.
		//
		// filterNAN
		//		Filter a NAN value that can occured during the computation process.

		void calculateDenominator();
		void findInputEntropy();
		void findOutputEntropy();
		void calculateJoinEntropy();
		void calculateEntropies();
		void reset();

		double filterNAN(double value);

	public:

		BiInformationCalculator();

		/**
		 * Calculate the mutual information passed through the system.
		 * This member function implements an algorithm defined in an article published in the BMC Sytems Biology Journal in 2009.
		 * 
		 * doi: 10.1186/1752-0509-3-9
		 * 
		 */

		void calculateMutualInformation();

		/**
		 * Set the concentrations of the input, output and channel.
		 *
		 * @param concentrations A std::vector of double values.
		 */
		void setConcentrations(std::vector<double> concentrations);

		/**
		 * Get the result of the Algorithm.
		 */

		double getMutualInformation();


};


#endif  /*  __BINFORMATION_CALCULATOR_HPP  */