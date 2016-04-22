#ifndef __BIVARIATE_STRATEGY_HPP
#define __BIVARIATE_STRATEGY_HPP


#include "InformationStrategy.hpp"
#include "../TransmissionMatrix/MatrixCalculator.hpp"
#include "../RootFinder/InformationRootFinder.hpp"
#include "../MutualInformation/BiInformationCalculator.hpp"

#include <vector>
#include <algorithm>

#define BIONESIDEDCOMPLEXSIZE 2
#define BICOMMUNICATIONSYSTEMSIZE 3

/**
 * An implementation of the InformationStrategy interface that computes information related results in the context of a bivariate system.
 * A bivariate system is a system that as exactly one complex as the input, one as output and one as channel.
 */


class BivariateStrategy: public InformationStrategy{

private:

	//---------------------------------
	// Private data members
	//---------------------------------
	//
	// error_matrix_
	//		A class that computes the transmission error's matrix.
	//
	// solver_
	//		A rootfinder that solves numerically an equations system.
	//
	// information_calculator_
	//		A class that computes the mutual information exchanged through the system.
	// kds
	//		Dissociation constants. These give an hint about whether or not an ProteinComplex is likely to be broken down. 

	MatrixCalculator* error_matrix_;
	InformationRootFinder* solver_;
	BiInformationCalculator* information_calculator_;
	double kd1_;
	double kd2_;
	double kd3_;

	//--------------------------------
	// Private member functions
	//--------------------------------
	//
	// initiateSolver
	//		Initiate the solver by retrieving needed paramaters from the data param.
	//
	// assignateKD
	//		Assign kd values from the data to the kds data members.

	void initiateSolver(InformationProteinsContainer* data);
	void assignateKD(InformationProteinsContainer* data);
	void calculateMutualInformation(std::vector<double> concentrations);

public:

	BivariateStrategy();
	virtual ~BivariateStrategy();

	/**
	 * Override the member function defined in the InformationStrategy interface.
	 *
	 * @see InformationStrategy
	 */

	void calculateInformationAndFillTable(std::shared_ptr<ResultTable> res, InformationProteinsContainer* data, bool data_changed);

};

#endif /* __BIVARIATE_STRATEGY_HPP */