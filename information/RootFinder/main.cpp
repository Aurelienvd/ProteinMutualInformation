#include <iostream>

#include "RootFinder.hpp"

// Kds values defined in the article. They will be given by the input manager later.

using namespace std;

int main(int argc, char** argv){

	RootFinder* finder = new RootFinder();

	cout<<"After finder init" << endl;

	finder->initiateFunction(0.014, 70, 0.47);

	finder->solveSystem();

	delete finder;
}