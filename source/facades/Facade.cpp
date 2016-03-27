#include "Facade.hpp"
#include "../mediators/ProcessMediator.hpp"

Facade::Facade(ProcessMediator* mediator): mediator_(mediator) {}

void Facade::jobDone()
{
	mediator_->colleagueJobDone(this);
}