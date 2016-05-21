#include "UserRequest.hpp"

UserRequest::UserRequest(): stream_data_(nullptr), algo_data_(nullptr) {}

int UserRequest::getUserChoice() const
{
	return user_choice_;
}

void UserRequest::setUserChoice(int user_choice)
{
	user_choice_ = user_choice;
}

std::shared_ptr<StreamRequestData> UserRequest::getStreamRequestData() const
{
	return stream_data_;
}

std::shared_ptr<AlgorithmRequestData> UserRequest::getAlgorithmRequestData() const
{
	return algo_data_;
}

void UserRequest::setStreamRequestData(std::shared_ptr<StreamRequestData> data)
{
	stream_data_.reset();
	stream_data_ = data;
}

void UserRequest::setAlgorithmRequestData(std::shared_ptr<AlgorithmRequestData> data)
{
	algo_data_.reset();
	algo_data_ = data;
}