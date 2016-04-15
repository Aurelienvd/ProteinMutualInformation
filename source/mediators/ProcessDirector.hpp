
/**
 * Mediator class that directs the execution of a process.	
 */

#ifndef __PROCESS_DIRECTOR_HPP
#define __PROCESS_DIRECTOR_HPP

#include "../facades/Facade.hpp"

class ProcessDirector {

public:

	virtual ~ProcessDirector() = default;

	/**
	 * Define what to do after that a colleague has finished its job.
	 *
	 * @param The colleague that just finished its job.
	 */

	virtual void colleagueJobDone(Facade*) = 0; 

protected:

	/** @name Constructors */
	//@{
	/** The default constructor
	 *
	 * @see ProcessDirector#createColleagues
	 */
	//@}
	ProcessDirector() = default;

	/**
	 * Create the mediator's colleagues.
	 */

	virtual void createColleagues() = 0;
};

#endif /* __PROCESS_DIRECTOR_HPP */