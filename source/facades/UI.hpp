#ifndef __UI_HPP
#define __UI_HPP

#include "Facade.hpp"
#include "../ui/MainMenu.hpp"

class UI : public Facade {

	private:

		MainMenu* menu_;

	public:

		UI(ProcessDirector* director);
		virtual ~UI();

		void mainloop();

};

#endif /* __UI_HPP */