#include "MatrixCalculator.hpp"

/*The concentration values given as parameters are defined in the data tables of the main program. They represent, for a simple complex Skp2-Cks1-p27 (with Cks1 the channel),
  the following probabilities: P(p27 = 1 | Skp2 = 0) and P(p27 = 0 | Skp2 = 1).
 */

MatrixCalculator::MatrixCalculator(): f_(0.0), g_(0.0) {}

double MatrixCalculator::calculateFunctionValue(double concent1, double concent2)
{
	double res = (concent1)/(concent1+concent2);

	return res;

}

void MatrixCalculator::fillMatrix()
{
	matrix[0][0] = 1 - f_; 
	matrix[0][1] = g_;
	matrix[1][0] = f_;
	matrix[1][1] = 1 - g_;
}

void MatrixCalculator::calculateError(std::vector<double> concentrations)
{
     

	if (concentrations.size() >= infoconfig::kBindingSite*2)
	{
		f_ = calculateFunctionValue(concentrations.at(0), concentrations.at(1));
		g_ = calculateFunctionValue(concentrations.at(2), concentrations.at(3));

		fillMatrix();

	}
	else
	{
		std::cout << "Not Enough concentration values" << std::endl;
	}


}

double MatrixCalculator::getInputError() const
{
	return f_;
}

double MatrixCalculator::getOutputError() const
{
	return g_;
}

void MatrixCalculator::printMatrix()
{
	for (unsigned int i = 0; i < MatrixCalculator::size; i++ )
	{
		std::cout << "| " << matrix[i][0] << "," << matrix[i][1] << " |" << std::endl;
	}

}