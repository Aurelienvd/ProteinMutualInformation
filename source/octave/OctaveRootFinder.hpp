#ifndef __OCTAVE_ROOT_FINDER_HPP
#define __OCTAVE_ROOT_FINDER_HPP

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "../utils/RNGenerator.hpp"
#include "../constants/constants.hpp"
#include "../utils/StringSplitter.hpp"

#define OCTAVEDIR "octave/"

/**
 * This class is a nonlinear equations solver. This solver will call gnu octave in order to solve an n-dimensionnal non linear system.
 *
 * The convergence to solutions is not guarenteed and different initial guesses might be needed.
 */


class OctaveRootFinder {

	private:

		std::vector<double> octave_solutions_;
		std::vector<double> upper_bounds_;
		std::vector<double> lower_bounds_;
		std::vector<double> values_;

		std::vector<double> getGuesses() const;
		void writeToFile(std::string filename, std::vector<double> data, std::string separator) const;
		void writeValues() const;
		void writeGuesses() const;
		void callOctave();
		void readRoots();

	public:

		OctaveRootFinder();

		void setUpperBounds(std::vector<double> bounds);
		void setValues(std::vector<double> values);
		void solve();

		std::vector<double> getSolutions() const;



};

#endif /* __OCTAVE_ROOT_FINDER_HPP  */