
/**
 * IOManaging Facade. The I/O operations defined here are file writing/reading operations.
 */


#ifndef __IO_MANAGER_HPP
#define __IO_MANAGER_HPP

#include <string>

#include "../io/InputDataManager.hpp"
#include "../communicationdata/ConcreteStream.hpp"
#include "Facade.hpp"


class IOManager: public Facade {

private:

	//-------------------------
	// Private data members
	//-------------------------
	//
	// manager_
	//		A class that will do the backend work.

	InputDataManager* manager_;

	//-------------------------
	// Private member functions
	//-------------------------
	//
	// jobDone
	//		Override the parent's method.

	void jobDone();

public:

	/** @name Constructors */
	//@{
	/**	Default constructor.
	 *
	 * @see Facade
	 */
	//@}

	IOManager(ProcessDirector* director);
	virtual ~IOManager();

	/**
	 * Updata the data that will be saved or loaded.
	 *
	 * This method indicates what/where to save data and where to load data from.
	 *
	 * @param streamData An ConcreteStream pointer that contains information about data to load/save.
	 *
	 * @see ConcreteStream
	 */

	void updateData(ConcreteStream* streamData) const;

	/**
	 * Save the data available.
	 *
	 * Use updateData before using saveData to change the data to save.
	 *
	 * @return A boolean value indicating if the I/O operation was successful or not.
	 */

	bool saveData() const;

	/**
	 * Load data from a file.
	 *
	 * Use updateData before using loadData to change the file which to load data from.
	 *
	 * @return A boolean value indicating if the I/O operation was successful or not.
	 */

	bool loadData();

	/**
	 * Get the Data loaded.
	 *
	 * Use loadData before using getData to get the data from a file.
	 *
	 * @return A ConcreteStream pointer that contains all the data loaded.
	 *
	 * @see ConcreteStream
	 */

	ConcreteStream* getData() const;


};

#endif  /* __IO_MANAGER_HPP */