#ifndef __OCTAVE_ROOT_FINDER_HPP
#define __OCTAVE_ROOT_FINDER_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "../constants/constants.hpp"


class OctaveRootFinder {

	private:

		std::vector<double> octave_solutions_;
		std::vector<double> upper_bounds_;

	public:

		OctaveRootFinder();

		void setUpperBounds(std::vector<double> bounds);
		void solve();

		std::vector<double> getSolutions() const;



};

#endif /* __OCTAVE_ROOT_FINDER_HPP  */