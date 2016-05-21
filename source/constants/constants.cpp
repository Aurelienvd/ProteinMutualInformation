#include <string>

namespace rfconfig{

	extern const long kRandomSeed = 7660048929382;
	extern const double kPrecision = 1e-6;
	extern const unsigned int kSystemSize = 6;
	extern const unsigned int kIteration = 1000;
	extern const double kLowerBound = 0;
	extern const double kConcentrationMinValue = 0.0001;
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
}

namespace error_indicator{

	extern const std::string kUnfoundComplexName = "Nullptr Complex";
}

namespace error_indications{

	extern const std::string kMissingInputDataIndications = "This error may be caused by inconsistent input data file or incorrect algorithmic constraints.";
}