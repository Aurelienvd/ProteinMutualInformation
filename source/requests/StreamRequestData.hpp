#ifndef __STREAM_REQUEST_DATA_HPP
#define __STREAM_REQUEST_DATA_HPP

#include <cstddef>

#include "../communicationdata/ConcreteStream.hpp"
#include <memory>

class StreamRequestData{

private:

	std::shared_ptr<ConcreteStream> data_;

public:

	StreamRequestData();
	virtual ~StreamRequestData() = default;

	std::shared_ptr<ConcreteStream> getData() const;
	void setData(std::shared_ptr<ConcreteStream> data);


};

#endif /* __STREAM_REQUEST_DATA_HPP */