#include "BivariateStrategy.hpp"


BivariateStrategy::BivariateStrategy(): error_matrix_(new MatrixCalculator()), solver_(new RootFinder()), information_calculator_(new BiInformationCalculator()) {}

BivariateStrategy::~BivariateStrategy()
{
	delete error_matrix_;
	delete solver_;
	delete information_calculator_;
}

void BivariateStrategy::initiateSolver()
{
	//solver_->initiateFunction(adt_->getInput()->getProteinConcentration(), adt_->getChannel()->getProteinConcentration(), adt_->getOutput()->getProteinConcentration());
}

void BivariateStrategy::calculateInformationAndFillTable(std::shared_ptr<ResultTable> res, InformationProteinsContainer* data)
{

}