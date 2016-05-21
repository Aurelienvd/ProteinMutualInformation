#include "BiResultTableRow.hpp"

BiResultTableRow::BiResultTableRow(double in, double chan, double out, double inerr, double outerr, double info): ResultTableRow(inerr, outerr, info), input_concentration_(in),
								   channel_concentration_(chan), output_concentration_(out) {}
								   

double BiResultTableRow::getInputConcentration() const
{
	return input_concentration_;
}
		
double BiResultTableRow::getChannelConcentration() const
{
	return output_concentration_;
}

double BiResultTableRow::getOutputConcentration() const
{
	return channel_concentration_;
}

std::string BiResultTableRow::toString() const
{
	double data[ROWSIZE] = {input_concentration_, channel_concentration_, output_concentration_, input_error_, output_error_, mutual_information_};
	std::string str = "";

	for (int i = 0; i < ROWSIZE; i++){
		str += TABSPACER + std::string(SPACERSIZE, ' ') + std::string(SPACERSIZE, ' ') + std::to_string(data[i]);
	}
	str += std::string(SPACERSIZE, ' ') + TABSPACER;

	return str;
}