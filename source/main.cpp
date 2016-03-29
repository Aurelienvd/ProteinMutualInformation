#include <iostream>

#include "mediators/MainProcessDirector.hpp"


using namespace std;

int main(int argc, char** argv){

	MainProcessDirector* director_ = new MainProcessDirector();

	director_->startProcess();
	delete director_;

	return 0;
}