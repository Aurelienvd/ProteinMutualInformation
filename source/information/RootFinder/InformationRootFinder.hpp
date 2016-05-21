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

#define DOUBLEPRECISION 3
#define SOLUTIONPRECISION 0.2

class InformationRootFinder: public RootFinder{

	typedef std::pair<int, double> unknown_init_pair;

	private:

		std::map<int, double> initial_guess_map_;
		std::vector<double> upper_bounds_;
		std::unique_ptr<RNGenerator> generator_;

		bool solutionsValid() const;

		void putInMap(int key, double value);
		void resetMap();

		void getFirstInitialGuesses();
		void getSecondInitialGuess();
		void getThirdInititalGuess();
		std::vector<double> getSolutionGuesses();
		bool checkConcentrations();

	public:

		InformationRootFinder();

		void setUpperBounds(std::vector<double> upper_bounds);
		void solve();




};

#endif /* __INFORMATION_ROOT_FINDER_HPP  */