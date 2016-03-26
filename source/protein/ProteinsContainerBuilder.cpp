#include "ProteinsContainerBuilder.hpp"


void ProteinsContainerBuilder::updateData(std::vector<std::string> proteins ,std::vector<std::string> partners, std::vector<std::string> constants)
{
	proteins_ = proteins;
	partners_ = partners;
	constants_ = constants;
}

void ProteinsContainerBuilder::buildGlobalProtein()
{

}

void ProteinsContainerBuilder::buildProteinComplexes()
{

}

void ProteinsContainerBuilder::buildProteinsContainer()
{

}

ProteinsContainer* ProteinsContainerBuilder::getProteinsContainer() const
{
	return proteins_container_;
}