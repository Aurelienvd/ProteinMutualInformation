#include "Plotter.hpp"

/*Plotter::Plotter(): plot_(Gnuplot()) {}


void Plotter::setTable(std::shared_ptr<ResultTable> table)
{
	table_.reset();
	table_ = table;
}

void Plotter::plotMutualInformation2d()
{
	std::vector<double> vals;

	for (auto row : table_->getRows()){
		vals.push_back(row->getMutualInformation());
	}

	plot_.plot_x(vals);
}

void Plotter::plotMutualInformation3d()
{

}

void Plotter::plotMutualInformation(bool channel_value_const)
{
	if (channel_value_const){
		plotMutualInformation2d();
	}
	else {
		plotMutualInformation3d();
	}

}*/