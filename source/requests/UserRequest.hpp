#ifndef __USER_REQUEST_HPP
#define __USER_REQUEST_HPP

#include <string>
#include <cstddef>

#include "StreamRequestData.hpp"
#include "AlgorithmRequestData.hpp"

class UserRequest {

private:
	
	std::shared_ptr<StreamRequestData> stream_data_;
	std::shared_ptr<AlgorithmRequestData> algo_data_;
	int user_choice_;

public:

	enum Choices {load = 1,  save = 2, start = 3, help = 4, quit = 5};

	UserRequest();
	~UserRequest() = default;

	int getUserChoice() const;
	std::shared_ptr<StreamRequestData> getStreamRequestData() const;
	std::shared_ptr<AlgorithmRequestData> getAlgorithmRequestData() const;
	void setUserChoice(int user_choice);
	void setStreamRequestData(std::shared_ptr<StreamRequestData> data);
	void setAlgorithmRequestData(std::shared_ptr<AlgorithmRequestData> data);
};

#endif /* __USER_REQUEST_HPP */