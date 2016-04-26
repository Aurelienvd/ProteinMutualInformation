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

std::vector<double> RootFinder::getSolutions() const
{
	return solutions;
}

void RootFinder::initiateFunction(double concent_1, double concent_2, double concent_3, double kd1, double kd2, double kd3)
{
	struct RootFinder::equilibrium_params p = {concent_1, concent_2, concent_3,kd1, kd2, kd3};
	f.f = &equilibrium_f;
	f.n = SYSTEMSIZE;
	f.params = &p;
}

void RootFinder::retrieveSolutions()
{
	std::vector<double> sol;
	for (unsigned int i = 0; i < SYSTEMSIZE; i++){
		if (i != 1 && i != 2){
			sol.push_back(gsl_vector_get (solver->x, i));
		}
	}
	solutions = sol;
}

void RootFinder::print_state(unsigned int iter)
{
  printf ("iter = %3u x = % .3f % .3f % .3f % .3f % .3f % .3f "
          "f(x) = % .3e % .3e % .3e % .3e % .3e % .3e\n",
          iter,
          gsl_vector_get (solver->x, 0), 
          gsl_vector_get (solver->x, 1),
          gsl_vector_get (solver->x, 2), 
          gsl_vector_get (solver->x, 3),
          gsl_vector_get (solver->x, 4), 
          gsl_vector_get (solver->x, 5),
          gsl_vector_get (solver->f, 0),
          gsl_vector_get (solver->f, 1),
          gsl_vector_get (solver->f, 2),
          gsl_vector_get (solver->f, 3),
          gsl_vector_get (solver->f, 4),  
          gsl_vector_get (solver->f, 5));
}

bool RootFinder::solutionsValid() const
{
	bool valid = true;
	for (unsigned int i = 0; valid && i < solutions.size(); i++){
		valid = (valid && (solutions.at(i) >= 0));
	}
	return valid;
}

void RootFinder::solveSystem(std::vector<double> initial_guess)
{
	int status;
	unsigned int iter = 0;

	gsl_vector *x = gsl_vector_alloc(SYSTEMSIZE);

	for (unsigned int i = 0; i < SYSTEMSIZE; i++){
		gsl_vector_set(x, i, initial_guess.at(i));
	}

	setSolver(x);

	do
	{
		iter++;
		status = gsl_multiroot_fsolver_iterate (solver);

		if(status)
			break;
		retrieveSolutions();
		status = gsl_multiroot_test_residual(solver->f, PRECISION);

	}while (status == GSL_CONTINUE && iter < ITERATION);

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

	const double y0 = x0 + x1 + x2 + x3 - concent1;
	const double y1 = x4 + x2 + x3 - concent2;
	const double y2 = x5 + x1 + x3 - concent3;
	const double y3 = ((x0 * x4) / x2) - kd1;
	const double y4 = ((x0 * x5) / x1) - kd2;
	const double y5 = ((x2 * x5) / x3) - kd3;


	gsl_vector_set (functions, 0, y0);
	gsl_vector_set (functions, 1, y1);
	gsl_vector_set (functions, 2, y2);
	gsl_vector_set (functions, 3, y3);
	gsl_vector_set (functions, 4, y4);
	gsl_vector_set (functions, 5, y5);

	return GSL_SUCCESS;
}
