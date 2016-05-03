#include "BiInformationCalculator.hpp"
#include <iostream>

//     Concentrations define as [Cks1], [Cks1-p27], [Skp2-Cks1], [Skp2-Cks1-p27]

BiInformationCalculator::BiInformationCalculator(): denominator(0), input_entropy(0), output_entropy(0), join_entropy(0) 
{
	for (unsigned int i =0; i < 4; i++){
		concentrations.push_back(i);
	}
}

void BiInformationCalculator::calculateDenominator()
{
	std::size_t size = concentrations.size();
	for (std::size_t i = 0; i < size; i++)
	{
		denominator += concentrations.at(i);
	}

	denominator = (denominator == 0 ? 0.1 : denominator);
}

void BiInformationCalculator::findInputEntropy()
{
	double input_probability;

	for (int i = 0; i < 2; i++)
	{
		input_probability = ((concentrations[2*i] + concentrations[(2*i)+1])/denominator);
		input_entropy += (input_probability)*(log2(input_probability));
	}

	input_entropy = (-1)*input_entropy;
	input_entropy = filterNAN(input_entropy);

}

void BiInformationCalculator::findOutputEntropy()
{
	double output_probability;

	for (int i = 0; i < 2; i++)
	{
		output_probability = ((concentrations[i%2] + concentrations[(i%2)+2])/denominator);
		output_entropy += ((output_probability)*(log2(output_probability)));
	}

	output_entropy = (-1)*output_entropy;
	output_entropy = filterNAN(output_entropy);

}

void BiInformationCalculator::calculateJoinEntropy()
{
	double join_probability;
	std::size_t size = concentrations.size();

	for (std::size_t i = 0; i < size; i++)
	{
		join_probability = (concentrations[i]/denominator);
		join_entropy += ((join_probability)*(log2(join_probability)));
	}

	join_entropy = (-1)*join_entropy;
	join_entropy = filterNAN(join_entropy);

}

void BiInformationCalculator::calculateEntropies()
{
	findInputEntropy();
	findOutputEntropy();
	calculateJoinEntropy();

}

double BiInformationCalculator::filterNAN(double value)
{
	double entropy = (value != value ? 0 : value);    // According to IEEE, value != value will return true only if value = nan;
	return entropy;
}

void BiInformationCalculator::reset()
{
	input_entropy = 0;
	output_entropy = 0;
	join_entropy = 0;
	denominator;
}

void BiInformationCalculator::setConcentrations(std::vector<double> concent)
{
	reset();
	for (unsigned int i = 0; i < 4; i++){
		concentrations[i] = concent.at(i);
	}
}

void BiInformationCalculator::calculateMutualInformation()
{
	calculateDenominator();
	calculateEntropies();

	mutual_information = input_entropy + output_entropy - join_entropy;
}

double BiInformationCalculator::getMutualInformation()
{
	return mutual_information;
}