#include "BiResultTableRow.hpp"

void BiResultTableRow::setInputConcentration(double concentration)
{
	input_concentration_ = concentration;
}


void BiResultTableRow::setChannelConcentration(double concentration)
{
	channel_concentration_ = concentration;
}


void BiResultTableRow::setOutputConcentration(double concentration)
{
	output_concentration_ = concentration;
}


std::string BiResultTableRow::toString() const
{
	double data[ROWSIZE] = {input_concentration_, channel_concentration_, output_concentration_, input_error_, output_error_, mutual_information_};
	std::string str = "";

	for (int i = 0; i < ROWSIZE; i++){
		str += SPACERSIZE + TABSPACER + SPACERSIZE + std::to_string(data[i]);
	}
	str += SPACERSIZE + TABSPACER;

	return str;
}