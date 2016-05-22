#ifndef __PLOTTER_HPP
#define __PLOTTER_HPP

#include <iostream>
#include <vector>
#include <memory>

#include "gnuplot_i.hpp"
#include "../information/ResultTable/ResultTable.hpp"

class Plotter {

	private:

		Gnuplot plot_;

		std::shared_ptr<ResultTable> table_;

		void plotMutualInformation2d();
		void plotMutualInformation3d();

	public:

		Plotter();

		void setTable(std::shared_ptr<ResultTable> table);

		void plotMutualInformation(bool channel_value_const);
};


#endif /*  __PLOTTER_HPP  */