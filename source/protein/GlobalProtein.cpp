#include "GlobalProtein.hpp"

GlobalProtein::GlobalProtein(Protein* protein): protein_(protein), total_concentration_(0) {}


Protein* GlobalProtein::getProtein() const
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

bool GlobalProtein::equalsTo(Protein* protein) const
{
	return *protein_ == *protein;
}