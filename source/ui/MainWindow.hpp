#ifndef __MAIN_WINDOW_HPP
#define __MAIN_WINDOW_HPP


#include <gtkmm.h>
#include "UiInputConveyor.hpp"

class MainWindow : public Gtk::Window {

	private:

	Glib::RefPtr<Gtk::CssProvider> css_;
	Glib::RefPtr<Gtk::Builder> builder_;

	UiInputConveyor* conveyor_;

	public:
		
		MainWindow(Glib::RefPtr<Gtk::CssProvider> ncss, Glib::RefPtr<Gtk::Builder> nbuilder);
		virtual ~MainWindow();

};





#endif /*   __MAIN_WINDOW_HPP   */

