# library for computing mutual information between protein.

### libraries needed:

	* gsl
	* octave

### Documentation:

Documentation is available in the doc folder. To generate new doc, one needs the doxygen program. This program will generate doc as html file.

### Lib design:

This library main design is defined with two patterns, the facade pattern and the mediator pattern. Each mediator has the responsability to mediate the process of a given task (such as running the whole program, including the ui.). The mediators only knows the facades, which are some sort of interfaces to submodules. Each submodules has a given task (IO, Adt building, UI, etc..). main.cpp contains examples of use.

### Module description:

	* communicationdata: Data types that will be shared between modules.
	* constants: module containing constants files.
	* data: directory containing data file with the .txt extension.
	* exceptions: module containing exception classes.
	* facades: module containing facades, according to the design described above. Only a facade has access to the classes of it's module.
	* information: module containing submodules for computing mutual information (again, ADT builder, IO, strategies, etc..).
	* io: module containing classes that perform I/O operations, merely read data.txt and write data.txt files.
	* mediators: module containing mediators, according to the design described above.
	* octave: module containing classes calling gnu octave + octave script for nonlinear solver.
	* protein: adt module, this module contains all the data that can be read from a data file.
	* requests: module solely used when the UI is called.
	* res: directory containing results of the algorithm. This directory includes a python file that can get a matrix of mutual information from a res file.
	* ui: module designed for launching an UI. As for now, the ui is a terminal.
	* utils: module containing utility classes and functions.

### FAQ:

1. The solutions aren't valid, what should I do ?

Because this library uses nonlinear solver, there are no guarantee about whether or not the solver will converge to valid solutions and that for any concentration values.
If the solutions found, i.e. the amount of mutual information obtained seems odd, chances are that the solver failed to converge for many values. If something like this occurs,
few things can be done. First of all, check with other concentration ranges. This could help to find better solutions. If it doesn't work, than the initial values of the solver are likely to need some changes. There are three files that contain logic about finding initial values. The first is information/RootFinder/InformationRootFinder. This class uses gnu multiroot solver to try to solve the system. Another one is octave/OctaveRootFinder, which calls gnu octave for solving the system. The last file is octave/multirootfinder.m. This file is actually called by OctaveRootFinder but contains also some logic if it fails to find correct solutions. Last thing one can do is to change the gsl multiroot solver and try other algorithms, such as hybrids or gnewton (if using with derivatives, i.e. with a precomputed Jacobian, see [gsl](https://www.gnu.org/software/gsl/manual/html_node/Multidimensional-Root_002dFinding.html) for more infos).


2. How do I compute multivariate mutual information ?

In it's current state, this library computes mutual information for one input, one channel and one output. Adding multivariate mutual information is actually quite trivial. All ones need to do is to adapt the strategy of the InformationAlgorithm facade to be a NVariateStrategy. This strategy  is quite similar to the bivariate strategy. The only module that need changes is the information module and the structure of a multivariatestrategy is exactly the same as for the bivariate strategy (just changes the system to solve (in RootFinder or in multirootfinder.m) and the MutualInformation and TransmissionMatrix classes are needed.)


3. Why does the program keeps telling me that the input data are invalid ?

In order to find the global proteins of the data set, the program performs a split over a specific character, defined in constants module. Please, be sure not to use this character in the name of the protein.