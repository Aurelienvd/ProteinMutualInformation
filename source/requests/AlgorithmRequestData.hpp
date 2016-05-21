#ifndef __ALGORITHM_REQUEST_DATA_HPP
#define __ALGORITHM_REQUEST_DATA_HPP

#include <cstddef>
#include <memory>

#include "../communicationdata/AlgorithmicConstraints.hpp"


class AlgorithmRequestData {

private:

	std::shared_ptr<AlgorithmicConstraints> data_;

public:

	AlgorithmRequestData();
	virtual ~AlgorithmRequestData() = default;

	std::shared_ptr<AlgorithmicConstraints> getData() const;
	void setData(std::shared_ptr<AlgorithmicConstraints> data);
};

#endif /* __ALGORITHM_REQUEST_DATA_HPP */