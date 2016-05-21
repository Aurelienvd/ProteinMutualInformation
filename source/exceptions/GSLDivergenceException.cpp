#include "GSLDivergenceException.hpp"

GSLDivergenceException::GSLDivergenceException(): std::runtime_error(error_msg::kGSLDivergenceBegin + std::to_string(rfconfig::kMaxTries) + error_msg::kGSLDivergenceEnd){}