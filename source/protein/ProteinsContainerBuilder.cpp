#include "ProteinsContainerBuilder.hpp"


void ProteinsContainerBuilder::updateData(ConcreteStream* data)
{
	proteins_ = data->getComplexes();
	partners_ = data->getPartners();
	constants_ = data->getConstants();
}

void ProteinsContainerBuilder::buildGlobalProtein()
{
	for (std::string protein : proteins_){
		
	}

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