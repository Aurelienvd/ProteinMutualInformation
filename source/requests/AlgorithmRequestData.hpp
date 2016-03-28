#ifndef __ALGORITHM_REQUEST_DATA_HPP
#define __ALGORITHM_REQUEST_DATA_HPP

#include <cstddef>

#include "RequestData.hpp"
#include "../communicationdata/AlgorithmicConstraints.hpp"


class AlgorithmRequestData: public RequestData {

private:

	AlgorithmicConstraints* data_;

public:

	AlgorithmRequestData();
	virtual ~AlgorithmRequestData();

	AlgorithmicConstraints* getData() const override;
	void setData(AlgorithmicConstraints* data);
};

#endif /* __ALGORITHM_REQUEST_DATA_HPP */