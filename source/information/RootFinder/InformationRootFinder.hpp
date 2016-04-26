#ifndef __INFORMATION_ROOT_FINDER_HPP
#define __INFORMATION_ROOT_FINDER_HPP

#include "RootFinder.hpp"
#include "../../utils/RNGenerator.hpp"
#include <vector>
#include <memory>

#define LOWERBOUND 0

class InformationRootFinder: public RootFinder{

	private:

		std::vector<double> upper_bounds_;
		std::unique_ptr<RNGenerator> generator_;

		std::vector<double> getFirstInitialGuesses() const;
		double getSecondInitialGuess() const;
		double getThirdInititalGuess() const;
		std::vector<double> getSolutionGuesses() const;

	public:

		InformationRootFinder();

		void setUpperBounds(std::vector<double> upper_bounds);
		void solve();




};

#endif /* __INFORMATION_ROOT_FINDER_HPP  */