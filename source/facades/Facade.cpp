#include "Facade.hpp"
#include "../mediators/ProcessDirector.hpp"

Facade::Facade(ProcessDirector* director): director_(director) {}

void Facade::jobDone()
{
	if (director_ != nullptr){
		director_->colleagueJobDone(this);
	}
}