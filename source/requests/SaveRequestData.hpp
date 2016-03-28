#ifndef __SAVE_REQUEST_DATA_HPP
#define __SAVE_REQUEST_DATA_HPP

#include <cstddef>

#include "../communicationdata/ConcreteStream.hpp"
#include "RequestData.hpp"

class SaveRequestData: public RequestData{

private:

	ConcreteStream* data_;

public:

	SaveRequestData();
	virtual ~SaveRequestData();

	ConcreteStream* getData() const override;
	void setData(ConcreteStream* data);


};

#endif /* __SAVE_REQUEST_DATA_HPP */