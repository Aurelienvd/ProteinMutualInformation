#ifndef __NRESULT_TABLE_ROW_HPP
#define __NRESULT_TABLE_ROW_HPP

#include "ResultTableRow.hpp"
#include <vector>

class NResultTableRow: public ResultTableRow{

	private:

		std::vector<double> inputs_concentration_;
		double channel_concentration_;
		double output_concentration_;

	public:

		NResultTableRow(std::vector<double> ins, double chan, double out, double inerr, double outerr, double info);

		virtual ~NResultTableRow() = default;

		std::vector<double> getInputsConcentration() const;
		double getChannelConcentration() const;
		double getOutputConcentration() const;

		std::string toString() const;
};


#endif /* __NRESULT_TABLE_ROW_HPP  */