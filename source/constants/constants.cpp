#include <string>

namespace rfconfig{

	extern const long kRandomSeed = 7660048929382;
	extern const double kGeneratorDoublePrecision = 3;
	extern const double kPrecision = 1e-6;
	extern const unsigned int kSystemSize = 6;
	extern const unsigned int kIteration = 1000;
	extern const double kConcentrationMinValue = 0.0001;
	extern const unsigned int kMaxTries = 300;
}

namespace rflowerbounds{

	extern const double kFirstBound = 0.1;
	extern const double kSecondBound = 0.1;
	extern const double kThirdBound = 0.1;
	extern const double kForthBound = 0.1;
	extern const double kFifthBound = 0.1;
	extern const double kSixthBound = 5.0;
}

namespace infoconfig{

	extern const double kZeroValue= 1e-9;
	extern const int kBIOneSidedComplexSize = 2;
	extern const int kBIWholeComplexSize = 3;
	extern const int kBindingSite = 2;
}

namespace error_msg{

	extern const std::string kWrongInputData = "Error in the input data";
	extern const std::string kMissingInputData = " missing required data to complete the process.";
	extern const std::string kGSLDivergenceBegin = "GSL failed to converge to valid solutions after "; 
	extern const std::string kGSLDivergenceEnd = " tries.";
}

namespace error_indicator{

	extern const std::string kUnfoundComplexName = "Nullptr Complex";
	extern const double kDivergence = -0.5;
}

namespace error_indications{

	extern const std::string kMissingInputDataIndications = "This error may be caused by inconsistent input data file or incorrect algorithmic constraints.";
	extern const std::string kGSLDivergenceIndications = "This error occurs when gsl, the library used to find roots of the system, doesn't provide accurate solutions. The initial guesses of the solver might need some changes.";
}

namespace progress{

	extern const std::string kSolveWithOctave = "Trying to solve the system by calling gnu octave...";
}

namespace octaveconfig{

	extern const std::string kRootsFilename = "roots";
	extern const std::string kValuesFilename = "values";
	extern const std::string kGuessesFilename = "guesses";
	extern const std::string kFileExtension = ".csv";
	extern const std::string kOutDataSeparator = ",";
	extern const std::string kOctaveCommand = "octave -q  ";
	extern const std::string kOctaveExeFile = "octave/multirootfinder.m";
}