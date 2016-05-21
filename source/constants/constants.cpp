#include <string>

namespace rfconfig{

	extern const long kRandomSeed = 7660048929382;
	extern const double kPrecision = 1e-6;
	extern const unsigned int kSystemSize = 6;
	extern const unsigned int kIteration = 1000;
	extern const double kLowerBound = 0;
	extern const double kConcentrationMinValue = 0.0001;
	extern const unsigned int kMaxTries = 300;
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
	extern const std::string kGSLDivergenceIndications = "This error occurs when gsl, the library used to find roots of the system, doesn't provide accurate solutions.\nThe initial guesses of the solver might need some changes.";
}

namespace progress{

	extern const std::string kSolveWithOctave = "Trying to solve the system by calling gnu octave ...";
}

namespace octaveconfig{

	extern const std::string kRootsFileName = "roots";
	extern const std::string kValuesFileName = "value";
	extern const std::string kGuessFilename = "guesses";
	extern const std::string kFileExtension = ".csv";
	extern const std::string kValueSeparator = ",";
}