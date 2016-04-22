#ifndef __INFORMATION_ROOT_FINDER_HPP
#define __INFORMATION_ROOT_FINDER_HPP

#include "RootFinder.hpp"
#include <vector>

#define LOWERBOUND 0
#define STEP 1

class InformationRootFinder: public RootFinder{

	private:

		std::vector<double> upper_bounds_;

		bool solutionsValid() const;
		std::vector<double> getInitialValues(int rep) const;

	public:

		void setUpperBounds(std::vector<double> upper_bounds);
		void solve();




};

#endif /* __INFORMATION_ROOT_FINDER_HPP  */