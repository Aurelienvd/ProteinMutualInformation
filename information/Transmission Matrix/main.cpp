#include <iostream>

#include "MatrixCalculator.hpp"
#include <vector>


using namespace std;


int main(int argc, char** argv)
{
	MatrixCalculator* calcul = new MatrixCalculator();
	vector<double> concentrations = {0.5,5.9,3,1.2};

	calcul->initiateMatrix(concentrations);
	calcul->printMatrix();


	delete calcul;

	return 0;
}