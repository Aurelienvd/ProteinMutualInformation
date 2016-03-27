#ifndef __CONCRETE_STREAM_HPP
#define __CONCRETE_STREAM_HPP

#include "Stream.hpp"
#include <string>
#include <sstream>


class ConcreteStream : public Stream{

	// This class is used to simplify the communication between this module and the other ones.

private:

	std::string filename_;
	
public:

	void setFilename(std::string filename) override;
	std::vector<double> getConstantsAsDoubleVector() const;
	static std::vector<std::string> splitComplex(std::string complex);
};


#endif /* __CONCRETE_STREAM_HPP  */