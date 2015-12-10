#ifndef __INFORMATION_CALCULATOR_HPP
#define __INFORMATION_CALCULATOR_HPP


#include <cmath>
#include <vector>

class InformationCalculator {


	private:

		double mutual_information;
		double input_entropy;
		double output_entropy;
		double join_entropy;
		double denominator;
		std::vector<double> concentrations;

		void calculateDenominator();
		void findInputEntropy();
		void findOutputEntropy();
		void calculateJoinEntropy();
		void calculateEntropies();

		double filterNAN(double value);

	public:

		InformationCalculator();

		void calculateMutualInformation();
		void setConcentrations(std::vector<double> concentrations);
		double getMutualInformation();


};


#endif  /*  __INFORMATION_CALCULATOR_HPP  */