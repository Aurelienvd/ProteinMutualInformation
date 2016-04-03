#ifndef __UI_HPP
#define __UI_HPP

#include <memory>

#include "Facade.hpp"
#include "../ui/MainMenu.hpp"

class UI : public Facade {

	private:

		MainMenu* menu_;
		std::shared_ptr<UserRequest> request_;

	public:

		UI(ProcessDirector* director);
		virtual ~UI();

		void jobDone();
		void mainloop();

		void setRequest(std::shared_ptr<UserRequest> request);
		std::shared_ptr<UserRequest> getRequest() const;
		void displayMessage(std::string msg) const;

};

#endif /* __UI_HPP */