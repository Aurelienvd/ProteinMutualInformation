#include "InformationRootFinder.hpp"
#include <iostream>


InformationRootFinder::InformationRootFinder(): generator_(std::unique_ptr<RNGenerator>(new RNGenerator())) 
{
	for (unsigned int i =0; i < SYSTEMSIZE; i++){
		initial_guess_map_.insert(unknown_init_pair(i, SHRT_MAX));
	}
}

void InformationRootFinder::setUpperBounds(std::vector<double> upper_bounds)
{
	for (double upper_bound  : upper_bounds){
		upper_bounds_.push_back(upper_bound);
	}
}

void InformationRootFinder::resetMap()
{
	for (unsigned int i = 0; i < SYSTEMSIZE; i++){
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

void InformationRootFinder::getFirstInitialGuesses()	// Indexes: 0,1,2,3
{
	unsigned int nb_guesses = 4;
	std::vector<double> initial_guess = generator_->generateNumberSeq(nb_guesses, upper_bounds_.at(0));
	for (unsigned int i = 0; i < nb_guesses; i++){
		putInMap(i, initial_guess.at(i));
	}
}
		
void InformationRootFinder::getSecondInitialGuess()		// Indexes 4, 2, 3
{
	unsigned int indexes[3] = {4,2,3};
	unsigned int size = 3;
	std::vector<double> initial_guess = generator_->generateNumberSeq(size, upper_bounds_.at(1));
	for (unsigned int i = 0; i < size; i++){
		putInMap(indexes[i], initial_guess.at(i));
	}

}

void InformationRootFinder::getThirdInititalGuess()		// Indexes 5,1,3
{
	unsigned int indexes[3] = {5,1,3};
	unsigned int size = 3;
	std::vector<double> initial_guess = generator_->generateNumberSeq(size, upper_bounds_.at(2));
	for (unsigned int i = 0; i < size; i++){
		putInMap(indexes[i], initial_guess.at(i));
	}
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
	bool solution_valid = false;
	int count = 1;
	while (!solution_valid){
		resetMap();
		solveSystem(getSolutionGuesses());
		solution_valid = solutionsValid();
		++count;
	}
}