#ifndef __CONCRETE_STREAM_HPP
#define __CONCRETE_STREAM_HPP

#include <string>
#include <sstream>

#include "../datamanaging/Stream.hpp"
#include "Data.hpp"


class ConcreteStream : public Stream, public Data{

private:

	std::string filename_;
	
public:

	virtual ~ConcreteStream() = default;

	void setFilename(std::string filename) override;
	std::string getFilename() const;
	std::vector<double> getConstantsAsDoubleVector() const;
	static std::vector<std::string> splitComplex(std::string complex);
};


#endif /* __CONCRETE_STREAM_HPP  */