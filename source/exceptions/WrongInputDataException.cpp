#include "WrongInputDataException.hpp"

WrongInputDataException::WrongInputDataException(): std::logic_error(error_msg::kWrongInputData){}

WrongInputDataException::WrongInputDataException(const std::string& msg): std::logic_error(error_msg::kWrongInputData + ", " + msg){}

MissingInputDataException::MissingInputDataException(): WrongInputDataException(error_msg::kMissingInputData) {}