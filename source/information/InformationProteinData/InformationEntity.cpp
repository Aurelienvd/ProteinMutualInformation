#include "InformationEntity.hpp"


InformationEntity::InformationEntity(): protein_(nullptr), related_complexes_() {}


GlobalProtein* InformationEntity::getProtein() const
{
	return protein_;
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

double InformationEntity::getProteinConcentration() const
{
	return protein_->getTotalConcentration();
}

void InformationEntity::setEntity(GlobalProtein* protein)
{
	protein_ = protein;
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