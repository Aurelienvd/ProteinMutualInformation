#include <iostream>
#include <cstddef>
#include <memory>
#include <cstdlib>
#include "protein/Protein.hpp"

#include "mediators/MainProcessDirector.hpp"
#include "gnuplot/Plotter.hpp"


using namespace std;

void test();

int main(int argc, char** argv){

	/*MainProcessDirector* director_ = new MainProcessDirector();

	director_->startProcess();
	delete director_;*/
	test();

	return 0;
}

void test(){

	std::shared_ptr<ConcreteStream> stream = std::make_shared<ConcreteStream>();
	stream->setFilename("2009_data.txt");
	IOManager io(nullptr);
	io.updateData(stream);
	io.loadData();
	ProteinData protein_adt(nullptr);
	protein_adt.constructADT(io.getData());

	std::shared_ptr<Protein> input = std::make_shared<Protein>("Skp2");
	std::shared_ptr<Protein> channel = std::make_shared<Protein>("Cks1");
	std::shared_ptr<Protein> output = std::make_shared<Protein>("p27");

	std::shared_ptr<AlgorithmicConstraints> constraints = std::make_shared<AlgorithmicConstraints>();
	constraints->setInput(input, 0.004, 0.2, 0.004);
	constraints->setOutput(output, 1, 50, 1);
	constraints->setChannel(channel, 0.1, 0.1, 0.1);
	constraints->setMutualInformationType(1);

	InformationCalculator calculator(nullptr);
	calculator.calculateInformation(protein_adt.getADT(), constraints);

	/*Plotter plotter;
	plotter.setTable(calculator.getResult());
	plotter.plotMutualInformation(true);*/

	// std::system("octave ../../Documents/octave/multirootfinder.m >> ../../Documents/octave/c++test.txt");
}