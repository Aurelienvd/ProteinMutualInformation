#include "RootFinder.hpp"
#include <iostream>


int equilibrium_f(const gsl_vector *x, void *params, gsl_vector* functions);


RootFinder::RootFinder()
{
	solver = gsl_multiroot_fsolver_alloc(type, SYSTEMSIZE);
}

RootFinder::~RootFinder()
{
	gsl_multiroot_fsolver_free(solver);
}

void RootFinder::setSolver(const gsl_vector *x)
{

	gsl_multiroot_fsolver_set(solver, &f, x);
}

void RootFinder::initiateFunction(double concent_1, double concent_2, double concent_3, double kd1, double kd2, double kd3)
{
	struct RootFinder::equilibrium_params p = {concent_1, concent_2, concent_3,kd1, kd2, kd3};
	f.f = &equilibrium_f;
	f.n = SYSTEMSIZE;
	f.params = &p;
}

void RootFinder::solveSystem(double val1, double val2, double val3, double val4, double val5, double val6)
{
	int status;
	unsigned int iter = 0;
	double x_init[SYSTEMSIZE] = {val1, val2, val3, val4, val5, val6};

	gsl_vector *x = gsl_vector_alloc(SYSTEMSIZE);

	for (unsigned int i = 0; i < SYSTEMSIZE; i++){
		gsl_vector_set(x, i, x_init[i]);
	}

	setSolver(x);

	do
	{
		iter++;
		status = gsl_multiroot_fsolver_iterate (solver);

		if(status)
			break;
		status = gsl_multiroot_test_residual(solver->f, PRECISION);

	}while (status == GSL_CONTINUE && iter < ITERATION);

	printf("status = %s\n", gsl_strerror(status));

	gsl_vector_free(x);
}


// non-member function definitions.

int equilibrium_f(const gsl_vector *x, void *params, gsl_vector* functions)
{
	double concent1 = ((struct RootFinder::equilibrium_params *) params)->concent_1;
	double concent2 = ((struct RootFinder::equilibrium_params *) params)->concent_2;
	double concent3 = ((struct RootFinder::equilibrium_params *) params)->concent_3;
	double kd1 = ((struct RootFinder::equilibrium_params *) params)->kd1;
	double kd2 = ((struct RootFinder::equilibrium_params *) params)->kd2;
	double kd3 = ((struct RootFinder::equilibrium_params *) params)->kd3;

	const double x0 = gsl_vector_get (x, 0);
	const double x1 = gsl_vector_get (x, 1);
	const double x2 = gsl_vector_get (x, 2);
	const double x3 = gsl_vector_get (x, 3);
	const double x4 = gsl_vector_get (x, 4);
	const double x5 = gsl_vector_get (x, 5);

	const double y0 = x0 + x3 + x4 + x5 - concent1;
	const double y1 = x1 + x4 + x5 - concent2;
	const double y2 = x2 + x3 + x5 - concent3;
	const double y3 = ((x0*x1)/x4) - kd1;
	const double y4 = ((x0*x2)/x3) - kd2;
	const double y5 = ((x4*x2)/x5) - kd3;


	gsl_vector_set (functions, 0, y0);
	gsl_vector_set (functions, 1, y1);
	gsl_vector_set (functions, 2, y2);
	gsl_vector_set (functions, 3, y3);
	gsl_vector_set (functions, 4, y4);
	gsl_vector_set (functions, 5, y5);

	return GSL_SUCCESS;
}
