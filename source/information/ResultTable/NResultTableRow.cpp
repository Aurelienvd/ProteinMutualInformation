#include "NResultTableRow.hpp"

NResultTableRow::NResultTableRow(std::vector<double> ins, double chan, double out, double inerr, double outerr, double info): ResultTableRow(inerr, outerr, info), inputs_concentration_(ins),
								   channel_concentration_(chan), output_concentration_(out) {}
								   

std::vector<double> NResultTableRow::getInputsConcentration() const
{
	return inputs_concentration_;
}
		
double NResultTableRow::getChannelConcentration() const
{
	return output_concentration_;
}

double NResultTableRow::getOutputConcentration() const
{
	return channel_concentration_;
}

std::string NResultTableRow::toString() const
{
	double data[5] = {channel_concentration_, output_concentration_, input_error_, output_error_, mutual_information_};
	std::string str = "";

	for (double in : inputs_concentration_){
		str += std::to_string(in);
		if (in < 10){
			str += " ";
		}
		str += std::string(8, ' ') + std::string(8, ' ');
	}

	for (int i = 0; i < 5; i++){
		str += std::to_string(data[i]);
		if (data[i] < 10){
			str += " ";
		}
		str += std::string(8, ' ') + std::string(8, ' ');
	}
	str += std::string(8, ' ');

	return str;
}