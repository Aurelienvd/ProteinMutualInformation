#include <iostream>
#include <cstddef>
#include <memory>
#include "protein/Protein.hpp"

#include "mediators/MainProcessDirector.hpp"


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

	ConcreteStream stream;
	stream.setFilename("2009_data.txt");
	IOManager io(nullptr);
	io.updateData(&stream);
	io.loadData();
	ProteinData protein_adt(nullptr);
	protein_adt.constructADT(io.getData());

	std::shared_ptr<Protein> input = std::make_shared<Protein>("p27");
	std::shared_ptr<Protein> channel = std::make_shared<Protein>("Cks1");
	std::shared_ptr<Protein> output = std::make_shared<Protein>("Skp2");

	AlgorithmicConstraints* constraints = new AlgorithmicConstraints();
	constraints->setInput(input, 0, 50, 1);
	constraints->setOutput(output, 0, 0.2, 0.004);
	constraints->setChannel(channel, 0.1, 0.1, 0.1);
	constraints->setMutualInformationType(1);

	InformationCalculator calculator(nullptr);
	calculator.calculateInformation(protein_adt.getADT(), constraints);

	delete constraints;
}