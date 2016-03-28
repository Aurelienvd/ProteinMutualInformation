#include "AlgorithmRequestData.hpp"

AlgorithmRequestData::AlgorithmRequestData(): data_(nullptr) {}

AlgorithmRequestData::~AlgorithmRequestData()
{
	delete data_;
}

AlgorithmicConstraints* AlgorithmRequestData::getData() const
{
	return data_;
}

void AlgorithmRequestData::setData(AlgorithmicConstraints* data)
{
	data_ = data;
}