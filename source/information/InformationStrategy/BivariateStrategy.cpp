#include "BivariateStrategy.hpp"


BivariateStrategy::BivariateStrategy(): error_matrix_(new MatrixCalculator()), solver_(new RootFinder()), information_calculator_(new BiInformationCalculator()) {}