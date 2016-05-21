#include "OctaveRootFinder.hpp"

OctaveRootFinder::OctaveRootFinder(): octave_solutions_(), upper_bounds_() {}


void OctaveRootFinder::setUpperBounds(std::vector<double> bounds)
{
	upper_bounds_ = bounds;
}


void OctaveRootFinder::solve()
{

}


std::vector<double> OctaveRootFinder::getSolutions() const
{
	return octave_solutions_;
}