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

	std::vector<ResultTableRow*> resultMatrix_;
	std::shared_ptr<Protein> input_;
	std::shared_ptr<Protein> channel_;
	std::shared_ptr<Protein> output_;

	std::string separator_;

	void createSeparator(unsigned int size);

public:

	void addInfo(ResultTableRow* result_row);
	std::string toString();

	void setInput(std::shared_ptr<Protein> input);
	void setChannel(std::shared_ptr<Protein> channel);
	void setOutput(std::shared_ptr<Protein> output);

};


#endif /* __RESULT_TABLE_HPP */