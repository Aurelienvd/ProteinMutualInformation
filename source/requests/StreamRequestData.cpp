#include "StreamRequestData.hpp"

StreamRequestData::StreamRequestData(): data_(nullptr) {}

StreamRequestData::~StreamRequestData()
{
	delete data_;
}

ConcreteStream* StreamRequestData::getData() const
{
	return data_;
}

void StreamRequestData::setData(ConcreteStream* data)
{
	data_ = data;
}