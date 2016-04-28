/**
 * A facade interface that will be used as colleagues by the ProcessDirector instances.
 *
 * @see ProcessDirector
 */


#ifndef __FACADE_HPP
#define __FACADE_HPP

 #include <cstddef>

class ProcessDirector;

class Facade {

protected:

	ProcessDirector* director_;

public:

	/** @name Constructors */
	//@{
	/** The default constructor. It takes a ProcessDirector because the mediator pattern implementated required a colleague to know it's director. */
	//@}

	Facade(ProcessDirector*);
	virtual ~Facade() = default;

	/**
	 * Indicate to the director that the job of the interface is done. The job done will be defined in sub-classes.
	 */
	virtual void jobDone();

};

#endif /* __FACADE_HPP */