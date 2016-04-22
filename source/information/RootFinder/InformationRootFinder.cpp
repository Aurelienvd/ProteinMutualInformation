#include "InformationRootFinder.hpp"
#include <iostream>
#include <algorithm>

void InformationRootFinder::setUpperBounds(std::vector<double> upper_bounds)
{
	for (double upper_bound  : upper_bounds){
		upper_bounds_.push_back(upper_bound);
	}
}

bool InformationRootFinder::solutionsValid() const
{
	bool valid = true;
	for (unsigned int i = 0; valid && i < solutions.size(); i++){
		valid = ((solutions.at(i) <= upper_bounds_.at(0)) && (LOWERBOUND <= solutions.at(i)));
	}
	return valid;
}

std::vector<double> InformationRootFinder::getInitialValues(int rep) const
{
	std::vector<double> initial_values;
	for (double upper : upper_bounds_){
		initial_values.push_back((((LOWERBOUND + rep*STEP) <= upper) ? (LOWERBOUND + rep*STEP): upper));
	}
	return initial_values;

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