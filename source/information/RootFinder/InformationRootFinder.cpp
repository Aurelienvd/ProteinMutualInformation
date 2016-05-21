#include "InformationRootFinder.hpp"
#include <iostream>

InformationRootFinder::InformationRootFinder(): initial_guess_map_(), upper_bounds_(), generator_(std::unique_ptr<RNGenerator>(new RNGenerator())) 
{
	for (unsigned int i =0; i < rfconfig::kSystemSize; i++){
		initial_guess_map_.insert(unknown_init_pair(i, SHRT_MAX));
		upper_bounds_.push_back(i);
	}
}

void InformationRootFinder::setUpperBounds(std::vector<double> upper_bounds)
{
	for (unsigned int i = 0; i < upper_bounds.size(); i++){
		upper_bounds_[i] = upper_bounds.at(i);
	}
}

void InformationRootFinder::resetMap()
{
	for (unsigned int i = 0; i < rfconfig::kSystemSize; i++){
		initial_guess_map_[i] = SHRT_MAX;
	}
}

void InformationRootFinder::putInMap(int key, double value)
{
	double val = initial_guess_map_.at(key);
	if (value < val){
		initial_guess_map_[key] = RNGenerator::getDoublePrecision(value, DOUBLEPRECISION);
	}
}

bool InformationRootFinder::solutionsValid() const
{
	bool valid = true;
	for (unsigned int i = 0; valid && i < rfconfig::kSystemSize; i++){
		valid = valid && (solutions.at(i) >= rfconfig::kConcentrationMinValue);
	}

	return valid;
}

void InformationRootFinder::getFirstInitialGuesses()	// Indexes: 0,1,2,3
{
	unsigned int nb_guesses = 4;
	std::vector<double> initial_guess = generator_->generateNumberSeq(nb_guesses, 0.01, upper_bounds_.at(0));
	for (unsigned int i = 0; i < nb_guesses; i++){
		putInMap(i, initial_guess.at(i));
	}
}
		
void InformationRootFinder::getSecondInitialGuess()		// Indexes 4, 2, 3
{
	unsigned int indexes[3] = {4,2,3};
	unsigned int size = 3;
	std::vector<double> initial_guess = generator_->generateNumberSeq(size, 0.01, upper_bounds_.at(1));
	for (unsigned int i = 0; i < size; i++){
		putInMap(indexes[i], initial_guess.at(i));
	}

}

void InformationRootFinder::getThirdInititalGuess()		// Indexes 5,1,3
{
	unsigned int indexes[3] = {5,1,3};
	unsigned int size = 3;
	std::vector<double> initial_guess = generator_->generateNumberSeq(size, 0.01, upper_bounds_.at(2));
	for (unsigned int i = 0; i < size; i++){
		putInMap(indexes[i], initial_guess.at(i));
	}
}

bool InformationRootFinder::checkConcentrations()
{
	bool solver_not_needed = false;
	for (unsigned int i = 0; !solver_not_needed && i < upper_bounds_.size(); i++){
		solver_not_needed = !solver_not_needed && (upper_bounds_.at(i) == 0);
	}
	return solver_not_needed;
}

std::vector<double> InformationRootFinder::getSolutionGuesses()
{
	std::vector<double> initial_guess;
	getFirstInitialGuesses();
	getSecondInitialGuess();
	getThirdInititalGuess();
	for (unsigned int i =0; i < initial_guess_map_.size(); i++){
		initial_guess.push_back(initial_guess_map_.at(i));
	}
	return initial_guess;
}

void InformationRootFinder::solve()
{
	bool solver_not_needed = checkConcentrations();
	if (!solver_not_needed){
		bool solution_valid = false;
		int count = 1;
		while (!solution_valid){
			resetMap();
			solveSystem(getSolutionGuesses());
			solution_valid = solutionsValid();
			++count;
		}
	} else{
		std::vector<double> sol;
		for (unsigned int i = 0; i < rfconfig::kSystemSize; i++){
			sol.push_back(rfconfig::kConcentrationMinValue);
		}
		solutions = sol;
	}
}