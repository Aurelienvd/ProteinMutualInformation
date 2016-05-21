#ifndef __GSL_DIVERGENCE_EXCEPTION_HPP
#define __GSL_DIVERGENCE_EXCEPTION_HPP


#include <stdexcept>
#include <exception>
#include <string>
#include "../constants/constants.hpp"


class GSLDivergenceException: public std::runtime_error{

	public:

		GSLDivergenceException();
};


#endif /*  __GSL_DIVERGENCE_EXCEPTION_HPP  */