#include <gtkmm.h>
#include <iostream>

#define XMLRC "rc/resource.glade"
#define CSS "rc/style.css"


int main(int argc, char *argv[])
{
 	Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv,"biochemical.information");

	Gtk::Window* mainwindow = nullptr;
    Glib::RefPtr<Gtk::CssProvider> css = Gtk::CssProvider::create();
	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create();

	try
    {
    	builder->add_from_file(XMLRC);
    }
    catch(const Glib::FileError& e)
    {
    	std::cerr << "FileError: " << e.what() << std::endl;
    	return 1;
    }

    css->load_from_path(CSS);

    builder->get_widget("MainWindow", mainwindow);
    mainwindow->get_style_context()->add_provider(css, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    mainwindow->maximize();

	return app->run(*mainwindow);
}