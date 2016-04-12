#include "InformationEntity.hpp"


InformationEntity::InformationEntity(): protein_(nullptr), related_complexes_(), range_(new Range()) {}

InformationEntity::~InformationEntity()
{
	delete range_;
}


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

std::vector<double> InformationEntity::getRange() const
{
	return range_->getRange();
}

float InformationEntity::getRangeMidValue() const
{
	return range_->getRangeMidValue();
}

double InformationEntity::getProteinConcentration() const
{
	return protein_->getTotalConcentration();
}

void InformationEntity::setProteinConcentration(double concent)
{
	protein_->setTotalConcentration(concent);
}

void InformationEntity::setEntity(GlobalProtein* protein)
{
	protein_ = protein;
}

void InformationEntity::setInitialValue(int val)
{
	range_->setInitialValue(val);
}

void InformationEntity::setFinalValue(int val)
{
	range_->setFinalValue(val);
}

void InformationEntity::setStep(float step)
{
	range_->setStep(step);
}

std::vector<double> InformationEntity::Range::getRange() const
{
	std::vector<double> range;
	for (double i = (double) initial_value_; i <= (double) final_value_; i+=step_){
		range.push_back(i);
	}
	return range;
}

float InformationEntity::Range::getRangeMidValue() const
{
	return ((final_value_-initial_value_)/2);
}