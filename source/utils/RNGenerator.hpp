#ifndef __RNGENERATOR_HPP
#define __RNGENERATOR_HPP

#include <random>
#include <vector>
#include <cmath>

#include "../constants/constants.hpp"


class RNGenerator {

	private:

		static long unsigned int seed;
		static std::minstd_rand generator;

	public:

		static double generateNumber();
		static double generateNumber(double upperbound);
		static double generateNumber(double lowerbound, double upperbound);

		static std::vector<double> generateNumberSeq(unsigned int size);
		static std::vector<double> generateNumberSeq(unsigned int size, double upperbound);
		static std::vector<double> generateNumberSeq(unsigned int size, double lowerbound, double upperbound);

		static double getDoublePrecision(double value, double precision);

};

#endif /* __RNGENERATOR_HPP  */