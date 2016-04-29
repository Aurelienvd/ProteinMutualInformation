#include "ResultTableWritter.hpp"

void ResultTableWritter::writeHeader(std::shared_ptr<ResultTable> table, std::ofstream* file) const
{
	*file << " Mutual Information + Errors Matrix for the complex definied as follows: \n";
	*file << " Input: " + table->getInput()->getProteinName() + " \n";
	*file << " Channel: " + table->getChannel()->getProteinName() + " \n";
	*file << " Output: " + table->getOutput()->getProteinName() + " \n";
	*file << " The fields are: Input concentration, Channel concentration, Output concentration, Input error, Output error, Mutual Information. \n\n\n";
}

bool ResultTableWritter::writeResultTable(std::shared_ptr<ResultTable> table, std::string filename) const
{
	mkdir(RESDIR, S_IRWXU|S_IRGRP|S_IXGRP);
	std::ofstream file(RESDIR+("/"+filename));

	if (file.is_open())
	{
		writeHeader(table, &file);
		file << table->toString();

		file.close();
		return true;
	}
	return false;
}