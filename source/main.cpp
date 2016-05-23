#include <iostream>
#include <cstddef>
#include <memory>
#include <cstdlib>
#include "protein/Protein.hpp"

#include "mediators/MainProcessDirector.hpp"
#include "gnuplot/Plotter.hpp"


using namespace std;

void test();
void save();

int main(int argc, char** argv){

	/*MainProcessDirector* director_ = new MainProcessDirector();

	director_->startProcess();
	delete director_;*/
	test();
	//save();

	return 0;
}

void test(){

	std::shared_ptr<ConcreteStream> stream = std::make_shared<ConcreteStream>();
	stream->setFilename("wasp_data.txt");
	IOManager io(nullptr);
	io.updateData(stream);
	io.loadData();
	ProteinData protein_adt(nullptr);
	protein_adt.constructADT(io.getData());

	std::shared_ptr<Protein> input = std::make_shared<Protein>("Cdc42");
	std::shared_ptr<Protein> channel = std::make_shared<Protein>("NWASP");
	std::shared_ptr<Protein> output = std::make_shared<Protein>("PIP2");

	std::shared_ptr<AlgorithmicConstraints> constraints = std::make_shared<AlgorithmicConstraints>();
	constraints->setInput(input, 0, 4, 0.08);
	constraints->setOutput(output, 0, 16, 0.32);
	constraints->setChannel(channel, 0.2, 0.2, 0.2);
	constraints->setMutualInformationType(1);

	InformationCalculator calculator(nullptr);
	calculator.calculateInformation(protein_adt.getADT(), constraints);

	Plotter plotter;
	plotter.setTable(calculator.getResult());
	plotter.plotMutualInformation(true);
}

void save(){
	std::vector<std::string> bases {"NWASP", "NWASP-Cdc42", "NWASP" , "NWASP-PIP2"};
	std::vector<std::string> partners {"Cdc42", "PIP2", "PIP2", "Cdc42"};
	std::vector<std::string> constants {"3", "0.02", "8", "0.008"};
	std::shared_ptr<ConcreteStream> stream = std::make_shared<ConcreteStream>();
	stream->setFilename("wasp_data.txt");
	stream->updateData(bases, partners, constants);
	IOManager io(nullptr);
	io.updateData(stream);
	io.saveData();
}