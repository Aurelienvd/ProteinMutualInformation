#ifndef __WRONG_INPUT_DATA_EXCEPTION
#define __WRONG_INPUT_DATA_EXCEPTION


#include <stdexcept>
#include <exception>
#include <string>
#include "../constants/constants.hpp"


class WrongInputDataException: public std::logic_error{

	public:

		WrongInputDataException();
		WrongInputDataException(const std::string& msg);
};

class MissingInputDataException: public WrongInputDataException{

	public:

		MissingInputDataException();


};


#endif /* __WRONG_INPUT_DATA_EXCEPTION */