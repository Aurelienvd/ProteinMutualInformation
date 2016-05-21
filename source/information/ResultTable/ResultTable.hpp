#ifndef __RESULT_TABLE_HPP
#define __RESULT_TABLE_HPP

#include <vector>
#include <string>
#include "ResultTableRow.hpp"
#include "../../protein/Protein.hpp"
#include <memory>

#define SEPSYMB '-'
#define BOUNDCHAR "|"


class ResultTable{

private:

	std::vector<std::shared_ptr<ResultTableRow>> resultMatrix_;
	std::shared_ptr<Protein> input_;
	std::shared_ptr<Protein> channel_;
	std::shared_ptr<Protein> output_;

	std::string separator_;

	void createSeparator(unsigned int size);

public:

	ResultTable();
	
	void addRow(std::shared_ptr<ResultTableRow> result_row);
	std::string toString();

	std::shared_ptr<Protein> getInput() const;
	std::shared_ptr<Protein> getChannel() const;
	std::shared_ptr<Protein> getOutput() const;
	std::vector<std::shared_ptr<ResultTableRow>> getRows() const;

	void setInput(std::shared_ptr<Protein> input);
	void setChannel(std::shared_ptr<Protein> channel);
	void setOutput(std::shared_ptr<Protein> output);

};


#endif /* __RESULT_TABLE_HPP */