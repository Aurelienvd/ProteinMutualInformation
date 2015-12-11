#include "MainWindow.hpp"

MainWindow::MainWindow(Glib::RefPtr<Gtk::CssProvider> ncss, Glib::RefPtr<Gtk::Builder> nbuilder): css_(ncss), builder_(nbuilder), conveyor_(new UiInputConveyor(builder_)) 
{
	this->get_style_context()->add_provider(css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

MainWindow::~MainWindow() 
{
	delete conveyor_;
}