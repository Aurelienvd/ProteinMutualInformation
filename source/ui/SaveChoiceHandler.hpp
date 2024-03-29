#ifndef __SAVE_CHOICE_HANDLER_HPP
#define __SAVE_CHOICE_HANDLER_HPP

#include <iostream>
#include <memory>

#include "../requests/StreamRequestData.hpp"

#define DELIMITER_ ';'

class SaveChoiceHandler {

	private:

		std::shared_ptr<StreamRequestData> request_data_;

		void saveData() const;
		std::vector<std::string> getComplexesFromUser() const;
		std::vector<std::string> getPartnersFromUser() const;
		std::vector<std::string> getConstantsFromUser() const;
		std::vector<std::string> getStringDataVectorFromUser(std::string message) const;
		std::string getFilenameFromUser() const;

	public:

		SaveChoiceHandler();

		void handleChoice();
		std::shared_ptr<StreamRequestData> getRequestData() const;
};

#endif /* __SAVE_CHOICE_HANDLER_HPP */