#ifndef __FACADE_HPP
#define __FACADE_HPP

class ProcessMediator;

class Facade {

private:

	ProcessMediator* mediator_;

public:

	Facade(ProcessMediator*);
	virtual void jobDone();

};

#endif /* __FACADE_HPP */