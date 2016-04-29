#ifndef __BIRESULT_TABLE_ROW_HPP
#define __BIRESULT_TABLE_ROW_HPP


#include "ResultTableRow.hpp"

#define TABSPACER "|"
#define SPACERSIZE 8
#define ROWSIZE 6


class BiResultTableRow: public ResultTableRow{

	private:

		double input_concentration_;
		double channel_concentration_;
		double output_concentration_;

	public:

		BiResultTableRow(double in, double chan, double out, double inerr, double outerr, double info);

		virtual ~BiResultTableRow() = default;

		double getInputConcentration() const;
		double getChannelConcentration() const;
		double getOutputConcentration() const;

		std::string toString() const;
};

#endif /* __BIRESULT_TABLE_ROW_HPP */