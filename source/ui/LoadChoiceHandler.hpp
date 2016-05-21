#ifndef __LOAD_CHOICE_HANDLER_HPP
#define __LOAD_CHOICE_HANDLER_HPP

#include <iostream>
#include <memory>

#include "../requests/StreamRequestData.hpp"

class LoadChoiceHandler {

	private:

		std::shared_ptr<StreamRequestData> request_data_;

	public:

		LoadChoiceHandler();

		void handleChoice();
		std::shared_ptr<StreamRequestData> getRequestData() const;



};

#endif /* __LOAD_CHOICE_HANDLER_HPP  */