#ifndef __MATRIX_CALCULATOR_HPP
#define __MATRIX_CALCULATOR_HPP


#include <vector>
#include <iostream>

#define BINDINGSITES 2

/**
 * This class calculates the transmission matrix. This matrix contains the information transmission values for different concentrations.
 * From this matrix, one can retrieve the error probabilities in the transmission process, according to an article published in the BMC Sytems Biology Journal in 2009.
 *
 * doi: 10.1186/1752-0509-3-9
 */


class MatrixCalculator {

	private:

		//---------------------------
		// Private data members
		//---------------------------
		//
		// size
		//		Size of the matrix.
		//
		// matrix
		// 		The transmission matrix.

		static const unsigned int size = 2;
		double matrix[size][size];

		//---------------------------
		// Private member functions
		//---------------------------
		//
		// calculateFunctionValue
		//		Calculate the value of the functions. These functions define the transmission value.
		//		The parameters give the value of the functions.
		//
		// fillMatrix
		//		Fill the matrix data member with the computed values.
		//		The parameters define the transmission value.

		double calculateFunctionValue(double concent1, double concent2);
		void fillMatrix(double f, double g);

	public:

		/**
		 * Initiate the matrix with a concentration vector.
		 *
		 * @param concentrations A vector of double values that will be used to compute the transmission values.
		 */

		void initiateMatrix(std::vector<double> concentrations);

		/**
		 * Print the current matrix state.
		 */

		void printMatrix();


};



#endif  /*  __MATRIX_CALCULATOR_HPP  */