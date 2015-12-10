#include "RootFinder.hpp"

/*
	The system is defined for Skp2-Cks1-p27 with x0 = [Cks1], x1 = [Skp2], x2 = [p27], x3 = [Cks1-p27], x4 = [Skp2-Cks1] and x5 = [Skp2-Cks1-p27]
	The values in y are y0 = [Cks1]0, y1 = [Skp2]0, y2 = [p27]0, y3 = Kd[Skp2-Cks1], y4 = Kd[Cks1-p27], y5 = Kd[Skp2-Cks1-p27]
*/

int equilibrium_f(const gsl_vector *x, void *params, gsl_vector* functions);


RootFinder::RootFinder()
{
	solver = gsl_multiroot_fsolver_alloc(type, n);
}

RootFinder::~RootFinder()
{
	gsl_multiroot_fsolver_free(solver);
}

void RootFinder::setSolver(const gsl_vector *x)
{

	gsl_multiroot_fsolver_set(solver, &f, x);
}

void RootFinder::print_state(unsigned int iter)
{
	printf("iter = %3u x = % .6f % .6f % .6f % .6f % .6f % .6f" "f(x) = % .3e % .3e % .3e % .3e % .3e % .3e\n", iter,
	gsl_vector_get(solver->x, 0), gsl_vector_get(solver->x, 1), gsl_vector_get(solver->x, 2), gsl_vector_get(solver->x, 3), gsl_vector_get(solver->x, 4),
	gsl_vector_get(solver->x, 5), gsl_vector_get(solver->f, 0), gsl_vector_get(solver->f, 1), gsl_vector_get(solver->f, 2), gsl_vector_get(solver->f, 3),
	gsl_vector_get(solver->f, 4), gsl_vector_get(solver->f, 5));
}

void RootFinder::initiateFunction(double concent_1, double concent_2, double concent_3, double kd1, double kd2, double kd3)
{
	struct RootFinder::equilibrium_params p = {concent_1, concent_2, concent_3,kd1, kd2, kd3};
	f.f = &equilibrium_f;
	f.n = n;
	f.params = &p;
}

void RootFinder::solveSystem()
{
	int status;
	unsigned int iter = 0;
	double x_init[6] = {-1,1,-2,2,-3,3};    // Ask for the initial values.

	gsl_vector *x = gsl_vector_alloc(n);

	for (unsigned int i = 0; i < 6; i++){
		gsl_vector_set(x, i, x_init[i]);
	}

	setSolver(x);

	print_state (iter);

	do
	{
		iter++;
		status = gsl_multiroot_fsolver_iterate (solver);
		print_state(iter);

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
