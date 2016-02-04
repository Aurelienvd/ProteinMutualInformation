#ifndef __RESULT_TABLE_HPP
#define __RESULT_TABLE_HPP

#include <vector>
#include <string>
#include "ResultTableRow.hpp"


class ResultTable{

private:

	std::vector<ResultTableRow> resultMatrix_;

public:

	void addInfo(ResultTableRow result_row);
	std::vector<ResultTableRow> getResultMatrix();

};


#endif /* __RESULT_TABLE_HPP */