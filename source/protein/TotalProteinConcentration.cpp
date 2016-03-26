#include "TotalProteinConcentration.hpp"

TotalProteinConcentration::TotalProteinConcentration(std::string protein): protein_(protein), total_concentration_(0) {}


std::string TotalProteinConcentration::getProtein() const
{
	return protein_;
}

double TotalProteinConcentration::getTotalConcentration() const
{
	return total_concentration_;
}

void TotalProteinConcentration::setTotalConcentration(double concentration)
{
	total_concentration_ = concentration;
}

bool TotalProteinConcentration::proteinEqualsTo(std::string protein) const
{
	return protein_ == protein;
}