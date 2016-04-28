#ifndef __RESULT_TABLE_ROW_HPP
#define __RESULT_TABLE_ROW_HPP

#include <string>


class ResultTableRow{

	protected:

		double input_error_;
		double output_error_;
		double mutual_information_;

	public:

		virtual ~ResultTableRow() = default;

		virtual std::string toString() const = 0;

		void setInputError(double error) {input_error_ = error;}
		void setOutputError(double error) {output_error_ = error;}
		void setMutualInformation(double info) {mutual_information_ = info;}



};


#endif /* __RESULT_TABLE_ROW_HPP */