#ifndef __MATRIX_CALCULATOR_HPP
#define __MATRIX_CALCULATOR_HPP


#include <vector>
#include <iostream>

#define BINDINGSITES 2


class MatrixCalculator {

	private:

		static const unsigned int size = 2;
		double matrix[size][size];

		double calculateFunctionValue(double concent1, double concent2);
		void fillMatrix(double f, double g);

	public:

		void initiateMatrix(std::vector<double> concentrations);
		void printMatrix();


};



#endif  /*  __MATRIX_CALCULATOR_HPP  */