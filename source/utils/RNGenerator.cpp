#include "RNGenerator.hpp"

long unsigned int RNGenerator::seed = std::chrono::system_clock::now().time_since_epoch().count();
std::minstd_rand RNGenerator::generator(seed);

unsigned int RNGenerator::generateNumber()
{
	return generator();
}

unsigned int RNGenerator::generateNumber(unsigned int upperbound)
{
	return (generator()%upperbound);
}

unsigned int RNGenerator::generateNumber(unsigned int lowerbound, unsigned int upperbound)
{
	return ((generator()%upperbound) + lowerbound);
}

std::vector<unsigned int> RNGenerator::generateNumberSeq(unsigned int size)
{
	std::vector<unsigned int> seq;
	for (unsigned int i = 0; i < size; i++){
		seq.push_back(generateNumber());
	}
	return seq;
}

std::vector<unsigned int> RNGenerator::generateNumberSeq(unsigned int size, unsigned int upperbound)
{
	std::vector<unsigned int> seq;
	for (unsigned int i = 0; i < size; i++){
		seq.push_back(generateNumber(upperbound));
	}
	return seq;
}

std::vector<unsigned int> RNGenerator::generateNumberSeq(unsigned int size, unsigned int lowerbound, unsigned int upperbound)
{
	std::vector<unsigned int> seq;
	for (unsigned int i = 0; i < size; i++){
		seq.push_back(generateNumber(lowerbound, upperbound));
	}
	return seq;
}