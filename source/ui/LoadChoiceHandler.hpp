#ifndef __LOAD_CHOICE_HANDLER_HPP
#define __LOAD_CHOICE_HANDLER_HPP

#include <iostream>

#include "../requests/StreamRequestData.hpp"

class LoadChoiceHandler {

	private:

		StreamRequestData* request_data_;

	public:

		LoadChoiceHandler();

		void handleChoice();
		StreamRequestData* getRequestData() const;



};

#endif /* __LOAD_CHOICE_HANDLER_HPP  */