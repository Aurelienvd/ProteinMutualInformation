#ifndef __RNGENERATOR_HPP
#define __RNGENERATOR_HPP

#include <chrono>
#include <random>
#include <vector>


class RNGenerator {

	private:

		static long unsigned int seed;
		static std::minstd_rand generator;

	public:

		static unsigned int generateNumber();
		static unsigned int generateNumber(unsigned int upperbound);
		static unsigned int generateNumber(unsigned int lowerbound, unsigned int upperbound);

		static std::vector<unsigned int> generateNumberSeq(unsigned int size);
		static std::vector<unsigned int> generateNumberSeq(unsigned int size, unsigned int upperbound);
		static std::vector<unsigned int> generateNumberSeq(unsigned int size, unsigned int lowerbound, unsigned int upperbound);

};

#endif /* __RNGENERATOR_HPP  */