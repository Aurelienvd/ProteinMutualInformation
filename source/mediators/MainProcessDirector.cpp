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

void MainProcessDirector::directLoadRequest() const
{
	
}

void MainProcessDirector::directSaveRequest() const
{

}

void MainProcessDirector::directStartRequest() const
{

}

void MainProcessDirector::manageUIJobDone() const
{
	auto request = ui_->getRequest();
	
	switch (request->getUserChoice()){
		case Choices::load: directLoadRequest();
			break;
		case Choices::save: directSaveRequest();
			break;
		default: directStartRequest();
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