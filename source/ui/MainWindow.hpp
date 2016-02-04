#ifndef __MAIN_WINDOW_HPP
#define __MAIN_WINDOW_HPP


#include <gtkmm.h>

class MainWindow : public Gtk::Window {

	private:

	Glib::RefPtr<Gtk::Builder> builder_;
	Gtk::Button* save_;

	protected:

	void on_button_save();


	public:
		
	MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& nbuilder);
	virtual ~MainWindow();

};





#endif /*   __MAIN_WINDOW_HPP   */

