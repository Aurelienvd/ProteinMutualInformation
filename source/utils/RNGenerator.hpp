#ifndef __RNGENERATOR_HPP
#define __RNGENERATOR_HPP

#include <chrono>
#include <random>
#include <vector>
#include <cmath>


class RNGenerator {

	private:

		static long unsigned int seed;
		static std::minstd_rand generator;

	public:

		static double generateNumber();
		static double generateNumber(unsigned int upperbound);
		static double generateNumber(unsigned int lowerbound, unsigned int upperbound);

		static std::vector<double> generateNumberSeq(unsigned int size);
		static std::vector<double> generateNumberSeq(unsigned int size, unsigned int upperbound);
		static std::vector<double> generateNumberSeq(unsigned int size, unsigned int lowerbound, unsigned int upperbound);

		static double getDoublePrecision(double value, double precision);

};

#endif /* __RNGENERATOR_HPP  */