
/**
 * This class represents a data type used by the program to communicate data through modules.
 *
 * This class contains stream related data, which means data loaded from the io module or entered by the user.
 *
 * @see InputDataManager
 */

#ifndef __CONCRETE_STREAM_HPP
#define __CONCRETE_STREAM_HPP

#include <string>
#include <sstream>

#include "../io/Stream.hpp"
#include "Data.hpp"


class ConcreteStream : public Stream, public Data{

private:

	//--------------------
	// Private data members
	//--------------------
	//
	// filename_
	//		The filename of the file from which or where to save data.

	std::string filename_;
	
public:

	ConcreteStream();
	virtual ~ConcreteStream() = default;

	//--------------------
	// Getters and Setters
	//--------------------

	/**
	 * Set the filename of the file from which or where to save data.
	 *
	 * @param filename A filename to find the correct file.
	 */

	void setFilename(std::string filename) override;

	/**
	 * Get the filename.
	 *
	 * @return filename A string containing the path to the corresponding file.
	 */

	std::string getFilename() const;

	/**
	 * Get the constants defined in the attribute of the upper class as an std::vector of doubles.
	 *
	 * @return A vector of double values.
	 *
	 * @see Stream
	 */

	std::vector<double> getConstantsAsDoubleVector() const;

	/**
	 * Split a string corresponding to a ProteinComplex.
	 *
	 * @param complex The string complex to split.
	 *
	 * @return A vector of string representing the splitted version of the param.
	 */

	static std::vector<std::string> splitComplex(std::string complex);
};


#endif /* __CONCRETE_STREAM_HPP  */