#include "MainProcessDirector.hpp"

MainProcessDirector::MainProcessDirector(): ui_(nullptr), data_manager_(nullptr), protein_adt_(nullptr), adt_(nullptr), calculator_(nullptr) 
{
	createColleagues();
}

MainProcessDirector::~MainProcessDirector()
{
	delete ui_;
	delete data_manager_;
	delete protein_adt_;
}

void MainProcessDirector::createColleagues()
{
	ui_ = new UI(this);
	data_manager_ = new DataManager(this);
	protein_adt_ = new ProteinData(this);
	calculator_ = new InformationCalculator(this);
}

void MainProcessDirector::directLoadRequest(RequestData* request_data)
{
	ConcreteStream* stream = dynamic_cast<ConcreteStream*>(request_data->getData());
	data_manager_->updateData(stream);
	data_manager_->loadData();
	ui_->displayMessage("Data loaded.");
}

void MainProcessDirector::directSaveRequest(RequestData* request_data)
{
	ConcreteStream* stream = dynamic_cast<ConcreteStream*>(request_data->getData());
	data_manager_->updateData(stream);
	data_manager_->saveData();
	ui_->displayMessage("Data saved.");
}

void MainProcessDirector::directStartRequest(RequestData* request_data)
{
	AlgorithmicConstraints* constraints = dynamic_cast<AlgorithmicConstraints*>(request_data->getData());
}

void MainProcessDirector::manageUIJobDone()
{
	auto request = ui_->getRequest();
	
	switch (request->getUserChoice()){
		case Choices::load: directLoadRequest(request->getRequestData());
			break;
		case Choices::save: directSaveRequest(request->getRequestData());
			break;
		default: directStartRequest(request->getRequestData());
			break;
	}
}

void MainProcessDirector::colleagueJobDone(Facade* facade)
{
	if (facade == ui_){
		manageUIJobDone();
	} else if (facade == data_manager_){
		protein_adt_->constructADT(data_manager_->getData());

	} else if (facade == protein_adt_){
		adt_ = protein_adt_->getADT();
	}
}

void MainProcessDirector::startProcess()
{
	ui_->mainloop();
}