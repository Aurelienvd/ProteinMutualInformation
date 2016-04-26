#include "InformationRootFinder.hpp"
#include <iostream>
#include <algorithm>


InformationRootFinder::InformationRootFinder(): generator_(std::make_unique<RNGenerator>()) {}

void InformationRootFinder::setUpperBounds(std::vector<double> upper_bounds)
{
	for (double upper_bound  : upper_bounds){
		upper_bounds_.push_back(upper_bound);
	}
}

std::vector<double> InformationRootFinder::getFirstInitialGuesses() const
{
	std::vector<double> initial_guess;

}
		
double InformationRootFinder::getSecondInitialGuess() const
{

}

double InformationRootFinder::getThirdInititalGuess() const
{

}

std::vector<double> InformationRootFinder::getSolutionGuesses() const
{
	std::vector<double> initial_guess = getFirstInitialGuesses();
	initial_guess.push_back(getSecondInitialGuess());
	initial_guess.push_back(getThirdInititalGuess());
	return initial_guess;
}

void InformationRootFinder::solve()
{
	bool solution_valid = false;
	int count = 1;
	while (!solution_valid){
		solveSystem(getInitialValues(count));
		solution_valid = solutionsValid();
		++count;
	}
}