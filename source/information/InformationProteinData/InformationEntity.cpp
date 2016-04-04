#include "InformationEntity.hpp"


InformationEntity::InformationEntity(GlobalProtein* protein): entity_(protein), related_complexes_() {}


GlobalProtein* InformationEntity::getEntity() const
{
	return entity_;
}

std::vector<ProteinComplex*> InformationEntity::getRelatedComplexes() const
{
	return related_complexes_;
}

void InformationEntity::addRelatedComplex(ProteinComplex* complex)
{
	related_complexes_.push_back(complex);
}