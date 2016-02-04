#include "MatrixCalculator.hpp"

/*The concentration values given as parameters are defined in the data tables of the main program. They represent, for a simple complex Skp2-Cks1-p27 (with Cks1 the channel),
  the following probabilities: P(p27 = 1 | Skp2 = 0) and P(p27 = 0 | Skp2 = 1).
 */



double MatrixCalculator::calculateFunctionValue(double concent1, double concent2)
{
	double res = (concent1)/(concent1+concent2);

	return res;

}

void MatrixCalculator::fillMatrix(double f, double g)
{
	matrix[0][0] = 1 - f; 
	matrix[0][1] = g;
	matrix[1][0] = f;
	matrix[1][1] = 1 - g;
}

void MatrixCalculator::initiateMatrix(std::vector<double> concentrations)
{
	double f;      // F defines the first probability (P(p27 = 1 | Skp2 = 0))
	double g;	  //  G defines the seconde one (P(p27 = 0 | Skp2 = 1))

	if (concentrations.size() >= BINDINGSITES*2)
	{
		f = calculateFunctionValue(concentrations.at(0), concentrations.at(1));
		g = calculateFunctionValue(concentrations.at(2), concentrations.at(3));

		fillMatrix(f, g);

	}
	else
	{
		std::cout << "Not Enough concentration values" << std::endl;
	}


}

void MatrixCalculator::printMatrix()
{
	for (unsigned int i = 0; i < MatrixCalculator::size; i++ )
	{
		std::cout << "| " << matrix[i][0] << "," << matrix[i][1] << " |" << std::endl;
	}

}