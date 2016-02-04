#include <iostream>

#include "InformationCalculator.hpp"
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
	InformationCalculator* info = new InformationCalculator();
	vector<double> concentrations = {0.1, 0.2, 0.2, 0.15};

	info->setConcentrations(concentrations);
	info->calculateMutualInformation();

	cout << "Mutual info = " << info->getMutualInformation() << " bits" << endl;


	delete info;

	return 0;
}