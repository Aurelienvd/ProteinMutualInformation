#include "InformationCalculator.hpp"

//     Concentrations define as [Cks1], [Cks1-p27], [Skp2-Cks1], [Skp2-Cks1-p27]

InformationCalculator::InformationCalculator(): denominator(0), input_entropy(0), output_entropy(0), join_entropy(0) {}

void InformationCalculator::calculateDenominator()
{
	std::size_t size = concentrations.size();
	for (std::size_t i = 0; i < size; i++)
	{
		denominator += concentrations.at(i);
	}

	denominator = (denominator == 0 ? 0.1 : denominator);

}

void InformationCalculator::findInputEntropy()
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

void InformationCalculator::findOutputEntropy()
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

void InformationCalculator::calculateJoinEntropy()
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

void InformationCalculator::calculateEntropies()
{
	findInputEntropy();
	findOutputEntropy();
	calculateJoinEntropy();

}

double InformationCalculator::filterNAN(double value)
{
	double entropy = (value != value ? 0 : value);    // According to IEEE, value != value will return true only if value = nan;
	return entropy;
}

void InformationCalculator::setConcentrations(std::vector<double> concent)
{
	concentrations = concent;
}

void InformationCalculator::calculateMutualInformation()
{
	calculateDenominator();
	calculateEntropies();

	mutual_information = input_entropy + output_entropy - join_entropy;

}

double InformationCalculator::getMutualInformation()
{
	return mutual_information;
}