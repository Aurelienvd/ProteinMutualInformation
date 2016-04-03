#include "InformationProcessDirector.hpp"
#include "../facades/InformationCalculator.hpp"

InformationProcessDirector::InformationProcessDirector(InformationCalculator* facade): upper_facade_(facade) 
{
	createColleagues();
}

InformationProcessDirector::~InformationProcessDirector() {}

void InformationProcessDirector::createColleagues()
{

}

void InformationProcessDirector::colleagueJobDone(Facade* facade)
{

}