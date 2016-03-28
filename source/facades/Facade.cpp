#include "Facade.hpp"
#include "../mediators/ProcessDirector.hpp"

Facade::Facade(ProcessDirector* director): director_(director) {}

void Facade::jobDone()
{
	director_->colleagueJobDone(this);
}