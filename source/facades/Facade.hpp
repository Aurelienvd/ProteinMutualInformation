#ifndef __FACADE_HPP
#define __FACADE_HPP

class ProcessDirector;

class Facade {

private:

	ProcessDirector* director_;

public:

	Facade(ProcessDirector*);
	virtual void jobDone();

};

#endif /* __FACADE_HPP */