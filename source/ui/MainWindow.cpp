#include "MainWindow.hpp"

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& nbuilder): Gtk::Window(cobject), builder_(nbuilder), save_(nullptr) 
{
	builder_->get_widget("saveButton", save_);
	if(save_)
    {
        save_->signal_clicked().connect( sigc::mem_fun(*this, &MainWindow::on_button_save) );
    }

}

MainWindow::~MainWindow() 
{
}

void MainWindow::on_button_save()
{
	
}