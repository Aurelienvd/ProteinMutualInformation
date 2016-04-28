#include "ResultTable.hpp"


void ResultTable::addInfo(ResultTableRow* result_row)
{
	resultMatrix_.push_back(result_row);
}

void ResultTable::setInput(std::shared_ptr<Protein> input)
{
	input_ = input;
}


void ResultTable::setChannel(std::shared_ptr<Protein> channel)
{
	channel_ = channel;
}


void ResultTable::setOutput(std::shared_ptr<Protein> output)
{
	output_ = output;
}

void ResultTable::createSeparator(unsigned int size)
{
	separator_ = BOUNDCHAR + std::string(size-2, SEPSYMB) + BOUNDCHAR + "\n";
}

std::string ResultTable::toString()
{
	createSeparator(resultMatrix_.at(0)->toString().size());
	std::string str = separator_;
	for (unsigned int i = 0; i < resultMatrix_.size(); i++){
		str += resultMatrix_.at(i)->toString() + "\n";
		str += separator_;
	}

	return str;
}