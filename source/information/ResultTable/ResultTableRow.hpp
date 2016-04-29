#ifndef __RESULT_TABLE_ROW_HPP
#define __RESULT_TABLE_ROW_HPP

#include <string>


class ResultTableRow{

	protected:

		double input_error_;
		double output_error_;
		double mutual_information_;

	public:

		ResultTableRow(double in, double out, double mutu): input_error_(in), output_error_(out), mutual_information_(mutu) {} 
		virtual ~ResultTableRow() = default;

		double getInputError() const {return input_error_;}
		double getOutputError() const {return output_error_;}
		double getMutualInformation() const {return mutual_information_;}

		virtual double getInputConcentration() const = 0;
		virtual double getChannelConcentration() const = 0;
		virtual double getOutputConcentration() const = 0;

		virtual std::string toString() const = 0;
};


#endif /* __RESULT_TABLE_ROW_HPP */