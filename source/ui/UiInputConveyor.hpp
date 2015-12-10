#ifndef __UI_INPUT_CONVEYOR_HPP
#define __UI_INPUT_CONVEYOR_HPP

#include <gtkmm.h>
#include <string>
#include <vector>
#include "../DataManaging/InputDataManager.hpp"



class UiInputConveyor {

	typedef std::vector<std::string> inputdata; 

private:

	Glib::RefPtr<Gtk::Builder> builder_;
	Gtk::TextView *complexes_;
	Gtk::TextView *partners_;
	Gtk::TextView *constants_;
	Gtk::Button *validation_;

	InputDataManager* input_manager_;

	getComplexesFromTextView();
	getPartnersFromTextView();
	getConstantsFromTextView();

protected:

	void conveyingProcedure();


public:

	UiInputConveyor(Glib::RefPtr<Gtk::Builder> builder);
	~UiInputConveyor();
};



#endif /*  __UI_INPUT_CONVEYOR_HPP  */