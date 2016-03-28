#include "SaveRequestData.hpp"

SaveRequestData::SaveRequestData(): data_(nullptr) {}

SaveRequestData::~SaveRequestData()
{
	delete data_;
}

ConcreteStream* SaveRequestData::getData() const
{
	return data_;
}

void SaveRequestData::setData(ConcreteStream* data)
{
	data_ = data;
}