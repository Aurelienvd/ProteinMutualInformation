#include "ResultTable.hpp"


ResultTable::ResultTable(): resultMatrix_(), input_(nullptr), channel_(nullptr), output_(nullptr){}

void ResultTable::addRow(std::shared_ptr<ResultTableRow> result_row)
{
	resultMatrix_.push_back(result_row);
}

std::shared_ptr<Protein> ResultTable::getInput() const
{
	return input_;
}

std::shared_ptr<Protein> ResultTable::getChannel() const
{
	return channel_;
}

std::shared_ptr<Protein> ResultTable::getOutput() const
{
	return output_;
}

std::vector<std::shared_ptr<ResultTableRow>> ResultTable::getRows() const
{
	return resultMatrix_;
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
	std::string str = "";
	for (unsigned int i = 0; i < resultMatrix_.size(); i++){
		str += resultMatrix_.at(i)->toString() + "\n";
	}

	return str;
}