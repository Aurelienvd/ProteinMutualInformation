#ifndef __START_CHOICE_HANDLER_CPP
#define __START_CHOICE_HANDLER_CPP

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <memory>

#include "../requests/AlgorithmRequestData.hpp"

#define RANGEDELIMITER ','

class StartChoiceHandler {

	private:

		std::shared_ptr<AlgorithmRequestData> request_data_;

		int getInformationTypeFromUser() const;
		std::string getProteinFromUser(std::string fonction) const;
		std::string getRangeFromUser(std::string fonction) const;
		std::vector<std::string> splitRange(std::string range) const;

		void setInputUserRequirements(std::shared_ptr<AlgorithmicConstraints> data);
		void setOutputUserRequirements(std::shared_ptr<AlgorithmicConstraints> data);
		void setChannelUserRequirements(std::shared_ptr<AlgorithmicConstraints> data);

	public:

		StartChoiceHandler();

		void handleChoice();
		std::shared_ptr<AlgorithmRequestData> getRequestData() const;

};

#endif /* __START_CHOICE_HANDLER_CPP */