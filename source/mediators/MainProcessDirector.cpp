#include "MainProcessDirector.hpp"

MainProcessDirector::MainProcessDirector(): ui_(nullptr), data_manager_(nullptr), protein_adt_(nullptr) 
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
}

void MainProcessDirector::directLoadRequest(RequestData* request_data)
{
	ConcreteStream* stream = dynamic_cast<ConcreteStream*>(request_data->getData());
	data_manager_->updateData(stream);
}

void MainProcessDirector::directSaveRequest(RequestData* request_data)
{
	ConcreteStream* stream = dynamic_cast<ConcreteStream*>(request_data->getData());
	data_manager_->updateData(stream);
	data_manager_->saveData();
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

	} else if (facade == protein_adt_){

	}
}

void MainProcessDirector::startProcess()
{
	ui_->mainloop();
}