#include "ResultTable.hpp"


void ResultTable::addInfo(ResultTableRow result_row)
{
	resultMatrix_.push_back(result_row);
}

std::vector<ResultTableRow> ResultTable::getResultMatrix()
{
	return resultMatrix_;
}