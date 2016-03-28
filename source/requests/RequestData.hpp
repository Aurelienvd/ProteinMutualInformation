#ifndef __REQUEST_DATA_HPP
#define __REQUEST_DATA_HPP

#include "../communicationdata/Data.hpp"

class RequestData {

public:

	virtual ~RequestData() = default;
	virtual Data* getData() const = 0;
};

#endif /* __REQUEST_DATA_HPP */