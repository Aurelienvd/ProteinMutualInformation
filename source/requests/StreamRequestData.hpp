#ifndef __STREAM_REQUEST_DATA_HPP
#define __STREAM_REQUEST_DATA_HPP

#include <cstddef>

#include "../communicationdata/ConcreteStream.hpp"
#include "RequestData.hpp"

class StreamRequestData: public RequestData{

private:

	ConcreteStream* data_;

public:

	StreamRequestData();
	virtual ~StreamRequestData();

	ConcreteStream* getData() const override;
	void setData(ConcreteStream* data);


};

#endif /* __STREAM_REQUEST_DATA_HPP */