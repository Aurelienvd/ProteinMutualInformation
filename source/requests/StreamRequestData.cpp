#include "StreamRequestData.hpp"

StreamRequestData::StreamRequestData(): data_(nullptr) {}

std::shared_ptr<ConcreteStream> StreamRequestData::getData() const
{
	return data_;
}

void StreamRequestData::setData(std::shared_ptr<ConcreteStream> data)
{
	data_.reset();
	data_ = data;
}