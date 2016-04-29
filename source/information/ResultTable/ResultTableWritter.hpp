#ifndef __RESULT_TABLE_WRITTER_HPP
#define __RESULT_TABLE_WRITTER_HPP

#include "ResultTable.hpp"

#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <sys/stat.h>

#define RESDIR "res"

class ResultTableWritter {

	private:

		void writeHeader(std::shared_ptr<ResultTable> table, std::ofstream* file) const;

	public:

		bool writeResultTable(std::shared_ptr<ResultTable> table, std::string filename) const;


};


#endif /*  __RESULT_TABLE_WRITTER_HPP  */