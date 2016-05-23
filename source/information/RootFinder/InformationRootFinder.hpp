#ifndef __INFORMATION_ROOT_FINDER_HPP
#define __INFORMATION_ROOT_FINDER_HPP

#include "RootFinder.hpp"
#include "../../utils/RNGenerator.hpp"
#include <vector>
#include <memory>
#include <map>
#include <limits.h>
#include "../../constants/constants.hpp"
#include "../../exceptions/GSLDivergenceException.hpp"

#define SOLUTIONPRECISION 0.2

/**
 * This class is a nonlinear root finder that will try to find roots for a system between some bounds by calling gsl MultiRoot Finder.
 * Because the system is non linear and numerically solved, there are no guarentee about whether or not the system will find correct solutions.
 */

class InformationRootFinder: public RootFinder{

	typedef std::pair<int, double> unknown_init_pair;

	private:

		std::map<int, double> initial_guess_map_;
		std::vector<double> upper_bounds_;
		std::unique_ptr<RNGenerator> generator_;

		bool solutionsValid() const;

		void putInMap(int key, double value);
		void resetMap();

		//
		//	Get initial guesses for the first linear equation of the system (i.e., the equation defined with the channel as left member).
		//

		void getFirstInitialGuesses();

		//
		//	Get initial guesses for the second linear equation of the system (i.e., the equation defined with the input as left member).
		//

		void getSecondInitialGuess();

		//
		//	Get initial guesses for the third linear equation of the system (i.e., the equation defined with the output as left member).
		//

		void getThirdInititalGuess();
		std::vector<double> getSolutionGuesses();
		bool checkConcentrations();

	public:

		InformationRootFinder();

		void setUpperBounds(std::vector<double> upper_bounds);
		void solve();




};

#endif /* __INFORMATION_ROOT_FINDER_HPP  */