#include "RNGenerator.hpp"

long unsigned int RNGenerator::seed = std::chrono::system_clock::now().time_since_epoch().count();
std::minstd_rand RNGenerator::generator(seed);

double RNGenerator::generateNumber()
{
	std::uniform_real_distribution<double> unif(0,1);
	return unif(generator);
}

double RNGenerator::generateNumber(unsigned int upperbound)
{
	std::uniform_real_distribution<double> unif(0, upperbound);
	return unif(generator);
}

double RNGenerator::generateNumber(unsigned int lowerbound, unsigned int upperbound)
{
	std::uniform_real_distribution<double> unif(lowerbound, upperbound);
	return unif(generator);
}

std::vector<double> RNGenerator::generateNumberSeq(unsigned int size)
{
	std::vector<double> seq;
	for (unsigned int i = 0; i < size; i++){
		seq.push_back(generateNumber());
	}
	return seq;
}

std::vector<double> RNGenerator::generateNumberSeq(unsigned int size, unsigned int upperbound)
{
	std::vector<double> seq;
	for (unsigned int i = 0; i < size; i++){
		seq.push_back(generateNumber(upperbound));
	}
	return seq;
}

std::vector<double> RNGenerator::generateNumberSeq(unsigned int size, unsigned int lowerbound, unsigned int upperbound)
{
	std::vector<double> seq;
	for (unsigned int i = 0; i < size; i++){
		seq.push_back(generateNumber(lowerbound, upperbound));
	}
	return seq;
}

double RNGenerator::getDoublePrecision(double value, double precision)
{
	return (floor((value * pow(10, precision) + 0.5)) / pow(10,precision));
}