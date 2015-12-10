#ifndef __ROOTFINDER_HPP
#define __ROOTFINDER_HPP

#include <stdio.h>
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include <vector>

#define ITERATION 1000
#define PRECISION 1e-7

class RootFinder {

	private:


		const gsl_multiroot_fsolver_type *type = gsl_multiroot_fsolver_hybrid;
		gsl_multiroot_fsolver* solver;
		gsl_multiroot_function f;    	//functions defining the system;
		const unsigned int n = 6;    		//Size of the system;

		void setSolver(const gsl_vector *x);
		void print_state(unsigned int iter);

	public:

		struct equilibrium_params{
			double kd1;
			double kd2;
			double kd3;
		};

		RootFinder();
		~RootFinder();

		void initiateFunction(double kd1, double kd2, double kd3);
		void solveSystem();


};



#endif /*  __ROOTFINDER_HPP  */