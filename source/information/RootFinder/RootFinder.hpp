#ifndef __ROOTFINDER_HPP
#define __ROOTFINDER_HPP

#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include <vector>

#define ITERATION 1000
#define PRECISION 1e-7
#define SYSTEMSIZE 6

class RootFinder {

	private:


		const gsl_multiroot_fsolver_type *type = gsl_multiroot_fsolver_hybrid;
		gsl_multiroot_fsolver* solver;
		gsl_multiroot_function f;    	//functions defining the system;

		void setSolver(const gsl_vector *x);
		void print_state(unsigned int iter);

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
		~RootFinder();

		void initiateFunction(double concent_1, double concent_2, double concent_3, double kd1, double kd2, double kd3);
		void solveSystem(double val1, double val2, double val3, double val4, double val5, double val6);		// vals represent the initial guess for a root value.


};



#endif /*  __ROOTFINDER_HPP  */