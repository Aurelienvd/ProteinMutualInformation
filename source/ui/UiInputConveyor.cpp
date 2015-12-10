#include "UiInputConveyor.hpp"


UiInputConveyor::UiInputConveyor(Glib::RefPtr<Gtk::Builder> builder): bulder_(builder), input_manager_(new InputDataManager()) 
{
	builder_->get_widget("complexes", complexes_);
	builder->get_widget("binding_partner", partners_);
    builder->get_widget("dissociation_constant", constants_);
    builder->get_widget("validationButton", validation_);

    validation_->signal_clicked().connect(sigc::mem_fun(*this, &UiInputConveyor::conveyingProcedure));
}

void UiInputConveyor::conveyingProcedure()
{
	
}

UiInputConveyor::~UiInputConveyor()
{
	delete input_manager_;
}

