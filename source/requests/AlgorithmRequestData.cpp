#include "AlgorithmRequestData.hpp"

AlgorithmRequestData::AlgorithmRequestData(): data_(nullptr) {}

std::shared_ptr<AlgorithmicConstraints> AlgorithmRequestData::getData() const
{
	return data_;
}

void AlgorithmRequestData::setData(std::shared_ptr<AlgorithmicConstraints> data)
{
	data_.reset();
	data_ = data;
}