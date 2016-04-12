#include "BivariateStrategy.hpp"


BivariateStrategy::BivariateStrategy(): error_matrix_(new MatrixCalculator()), solver_(new RootFinder()), information_calculator_(new BiInformationCalculator()) {}

BivariateStrategy::~BivariateStrategy()
{
	delete error_matrix_;
	delete solver_;
	delete information_calculator_;
}