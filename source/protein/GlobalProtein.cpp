#include "GlobalProtein.hpp"

GlobalProtein::GlobalProtein(std::shared_ptr<Protein> protein): protein_(protein), total_concentration_(0) {}


std::shared_ptr<Protein> GlobalProtein::getProtein() const
{
	return protein_;
}

std::string GlobalProtein::getProteinName() const
{
	return protein_->getProteinName();
}

double GlobalProtein::getTotalConcentration() const
{
	return total_concentration_;
}

void GlobalProtein::setTotalConcentration(double concentration)
{
	total_concentration_ = concentration;
}

bool GlobalProtein::equalsTo(std::shared_ptr<Protein> protein) const
{
	return *protein_ == *protein;
}