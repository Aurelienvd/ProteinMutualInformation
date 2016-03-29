#include "UI.hpp"

UI::UI(ProcessDirector* director): Facade(director), menu_(new MainMenu()) {}

UI::~UI()
{
	delete menu_;
}

void UI::mainloop()
{
	menu_->mainloop();
}