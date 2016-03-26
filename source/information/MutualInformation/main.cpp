#include <iostream>

#include "BiInformationCalculator.hpp"
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	BiInformationCalculator* info = new BiInformationCalculator();
	vector<double> concentrations = {0.1, 0.2, 0.2, 0.15};

	info->setConcentrations(concentrations);
	info->calculateMutualInformation();

	cout << "Mutual info = " << info->getMutualInformation() << " bits" << endl;


	delete info;

	return 0;
}