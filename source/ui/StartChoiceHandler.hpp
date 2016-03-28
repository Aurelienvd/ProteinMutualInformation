#ifndef __START_CHOICE_HANDLER_CPP
#define __START_CHOICE_HANDLER_CPP

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

#include "../requests/AlgorithmRequestData.hpp"

#define RANGEDELIMITER ','

class StartChoiceHandler {

	private:

		AlgorithmRequestData* request_data_;

		int getInformationTypeFromUser() const;
		std::string getProteinFromUser(std::string fonction) const;
		std::string getRangeFromUser(std::string fonction) const;
		std::vector<std::string> splitRange(std::string range) const;

		void setInputUserRequirements(AlgorithmicConstraints* data);
		void setOutputUserRequirements(AlgorithmicConstraints* data);
		void setChannelUserRequirements(AlgorithmicConstraints* data);

	public:

		StartChoiceHandler();

		void handleChoice();
		AlgorithmRequestData* getRequestData() const;

};

#endif /* __START_CHOICE_HANDLER_CPP */