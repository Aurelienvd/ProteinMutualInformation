#ifndef __SAVE_REQUEST_DATA_HPP
#define __SAVE_REQUEST_DATA_HPP

#include <cstddef>

#include "../datamanaging/ConcreteStream.hpp"

class SaveRequestData {

private:

	ConcreteStream* data_;

public:

	SaveRequestData();

	ConcreteStream* getData()
	void setData(ConcreteStream* data);


};

#endif /* __SAVE_REQUEST_DATA_HPP */