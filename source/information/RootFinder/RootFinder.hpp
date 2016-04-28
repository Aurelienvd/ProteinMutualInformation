#ifndef __ROOTFINDER_HPP
#define __ROOTFINDER_HPP

#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include <vector>

#define ITERATION 1000
#define PRECISION 1e-5
#define SYSTEMSIZE 6

/**
 * A class that solves a linear system with 6 equations and 6 unkwown variables.
 *
 * This class uses the GNU Scientific Library in order to solve the system.
 * 
 * @see http://www.gnu.org/software/gsl/manual/html_node/Multidimensional-Root_002dFinding.html#Multidimensional-Root_002dFinding
 */

class RootFinder {

	protected:

		//------------------------
		// Private data members.
		//------------------------
		//
		// type
		//		The type of the solver. Here, it is a multiroot solver because the system's size is 6.
		//
		// solver
		//		The solver.
		//
		// f
		//		The function that will be solved by the solver.
		//
		// solutions
		//		The solution found for the system.


		const gsl_multiroot_fsolver_type *type = gsl_multiroot_fsolver_hybrid;
		gsl_multiroot_fsolver* solver;
		gsl_multiroot_function f;
		std::vector<double> solutions;

		//-----------------------
		// Private member functions
		//-----------------------
		//
		// setSolver
		//		Initiate the solver.
		//
		// print_state
		//		Print the internal state of the solver during an iteration.
		//
		// retrieveSolutions
		//		Retrieve the solutions from the solver and add them to data member solutions.

		void setSolver(const gsl_vector *x);
		void print_state(unsigned int iter);
		void retrieveSolutions();

	public:

		struct equilibrium_params{
			double concent_1;
			double concent_2;
			double concent_3;
			double kd1;
			double kd2;
			double kd3;
		};

		RootFinder();

		/**
		 * Initiate the function that will be solved by the solver.
		 *
		 * The parameters are used to initialise the system.
		 *
		 * @see http://www.gnu.org/software/gsl/manual/html_node/Multidimensional-Root_002dFinding.html#Multidimensional-Root_002dFinding
		 */

		void initiateFunction(double concent_1, double concent_2, double concent_3, double kd1, double kd2, double kd3);

		/**
		 * Solve the system. The equation system is defined according to an article published in the BMC Sytems Biology Journal in 2009.
		 *
		 * The parameters represent the initial guess for the 6 unkown values.
		 * These will be refined to find the real solutions of the system.
		 *
		 * @see doi: 10.1186/1752-0509-3-9
		 */

		void solveSystem(std::vector<double> initial_guess);		// vals represent the initial guess for a root value.

		/**
		 * Get the solutions found for the systems.
		 *
		 * @return A vector of solutions.
		 */

		std::vector<double> getSolutions() const;


};



#endif /*  __ROOTFINDER_HPP  */