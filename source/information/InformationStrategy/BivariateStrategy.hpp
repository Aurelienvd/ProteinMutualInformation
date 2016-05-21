#ifndef __BIVARIATE_STRATEGY_HPP
#define __BIVARIATE_STRATEGY_HPP


#include "InformationStrategy.hpp"
#include "../TransmissionMatrix/MatrixCalculator.hpp"
#include "../RootFinder/InformationRootFinder.hpp"
#include "../MutualInformation/BiInformationCalculator.hpp"
#include "../ResultTable/BiResultTableRow.hpp"
#include "../../octave/OctaveRootFinder.hpp"

#include <vector>
#include <algorithm>
#include <memory>
#include "../../constants/constants.hpp"
#include "../../exceptions/GSLDivergenceException.hpp"

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

	std::unique_ptr<MatrixCalculator> error_matrix_;
	std::unique_ptr<InformationRootFinder> solver_;
	std::unique_ptr<BiInformationCalculator> information_calculator_;
	std::unique_ptr<OctaveRootFinder> octave_solver_;
	double kd1_;
	double kd2_;
	double kd3_;
	bool gsl_diverged_;

	//--------------------------------
	// Private member functions
	//--------------------------------
	//
	// initiateSolver
	//		Initiate the solver by retrieving needed paramaters from the data param.
	//
	// assignateKD
	//		Assign kd values from the data to the kds data members.

	void initiateSolver(std::shared_ptr<InformationProteinsContainer> data);
	void initiateOctaveSolver(std::shared_ptr<InformationProteinsContainer> data, std::vector<double> bounds);
	void assignateKD(std::shared_ptr<InformationProteinsContainer> data);
	void calculateMutualInformation(std::vector<double> concentrations);
	void calculateErrorMatrix(std::vector<double> concentrations);
	void displayProgressMsg(const std::string& msg) const;
	void saveResult(std::shared_ptr<ResultTable> res, std::shared_ptr<InformationProteinsContainer> data);

public:

	BivariateStrategy();
	virtual ~BivariateStrategy() = default;

	/**
	 * Override the member function defined in the InformationStrategy interface.
	 *
	 * @see InformationStrategy
	 */

	void calculateInformationAndFillTable(std::shared_ptr<ResultTable> res, std::shared_ptr<InformationProteinsContainer> data, bool data_changed);

};

#endif /* __BIVARIATE_STRATEGY_HPP */