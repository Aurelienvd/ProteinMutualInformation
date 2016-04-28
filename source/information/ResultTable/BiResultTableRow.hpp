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

		virtual ~BiResultTableRow() = default;

		std::string toString() const;

		void setInputConcentration(double concentration);
		void setChannelConcentration(double concentration);
		void setOutputConcentration(double concentration);



};

#endif /* __BIRESULT_TABLE_ROW_HPP */