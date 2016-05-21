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
	extern const unsigned int kMaxTries;
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
	extern const std::string kGSLDivergenceBegin;
	extern const std::string kGSLDivergenceEnd;
}


// Detects if an error occured.

namespace error_indicator{

	extern const std::string kUnfoundComplexName;
	extern const double kDivergence;
}

// Indications of the cause of the error.

namespace error_indications{

	extern const std::string kMissingInputDataIndications;
	extern const std::string kGSLDivergenceIndications;
}


#endif /* __CONSTANTS_HPP */