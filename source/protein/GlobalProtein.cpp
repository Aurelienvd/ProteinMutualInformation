#include "GlobalProtein.hpp"

GlobalProtein::GlobalProtein(std::string protein): protein_(protein), total_concentration_(0) {}


std::string GlobalProtein::getProtein() const
{
	return protein_;
}

double GlobalProtein::getTotalConcentration() const
{
	return total_concentration_;
}

void GlobalProtein::setTotalConcentration(double concentration)
{
	total_concentration_ = concentration;
}

bool GlobalProtein::proteinEqualsTo(std::string protein) const
{
	return protein_ == protein;
}