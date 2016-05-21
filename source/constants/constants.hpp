#ifndef __CONSTANTS_HPP
#define __CONSTANTS_HPP


#include <string>


//	RF => Root Finder.

namespace rfconfig{

	extern const long kRandomSeed;
	extern const double kPrecision;
	extern const unsigned int kSystemSize;
	extern const unsigned int kIteration;
	extern const double kLowerBound;
	extern const double kConcentrationMinValue;
}

namespace infoconfig{

	extern const double kZeroValue;
	extern const int kBIOneSidedComplexSize;
	extern const int kBIWholeComplexSize;
	extern const int kBindingSite;
}

// Basic error msg.

namespace error_msg{

	extern const std::string kWrongInputData;
	extern const std::string kMissingInputData;
}


// Detects if an error occured.

namespace error_indicator{

	extern const std::string kUnfoundComplexName;
}

// Indications of the cause of the error.

namespace error_indications{

	extern const std::string kMissingInputDataIndications;
}


#endif /* __CONSTANTS_HPP */