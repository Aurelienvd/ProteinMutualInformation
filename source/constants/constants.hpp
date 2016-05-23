#ifndef __CONSTANTS_HPP
#define __CONSTANTS_HPP


#include <string>


//	RF => Root Finder.

namespace rfconfig{

	extern const long kRandomSeed;
	extern const double kGeneratorDoublePrecision;
	extern const double kPrecision;
	extern const unsigned int kSystemSize;
	extern const unsigned int kIteration;
	extern const double kConcentrationMinValue;
	extern const unsigned int kMaxTries;
}

namespace rflowerbounds{

	extern const double kFirstBound;
	extern const double kSecondBound;
	extern const double kThirdBound;
	extern const double kForthBound;
	extern const double kFifthBound;
	extern const double kSixthBound;
}

namespace infoconfig{

	extern const double kZeroValue;
	extern const int kBIOneSidedComplexSize;
	extern const int kBIWholeComplexSize;
	extern const int kBindingSite;
	extern const int kNbComplexBoundToChannel;
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

namespace progress{

	extern const std::string kSolveWithOctave;
}


namespace octaveconfig{

	extern const std::string kRootsFilename;
	extern const std::string kValuesFilename;
	extern const std::string kGuessesFilename;
	extern const std::string kFileExtension;
	extern const std::string kOutDataSeparator;
	extern const std::string kOctaveCommand;
	extern const std::string kOctaveExeFile;
}


#endif /* __CONSTANTS_HPP */