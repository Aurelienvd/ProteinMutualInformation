#include "InformationEntity.hpp"


InformationEntity::InformationEntity(): entity_(nullptr), related_complexes_() {}


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

int InformationEntity::getInitialValue() const
{
	return initial_value_;
}

int InformationEntity::getFinalValue() const
{
	return final_value_;
}

float InformationEntity::getStep() const
{
	return step_;
}
void InformationEntity::setEntity(GlobalProtein* entity)
{
	entity_ = entity;
}

void InformationEntity::setInitialValue(int val)
{
	initial_value_ = val;
}

void InformationEntity::setFinalValue(int val)
{
	final_value_ = val;
}

void InformationEntity::setStep(float step)
{
	step_ = step;
}