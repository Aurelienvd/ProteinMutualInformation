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

void MainProcessDirector::colleagueJobDone(Facade* facade)
{
	if (facade == ui_){

	} else if (facade == data_manager_){

	} else if (facade == protein_adt_){

	}
}

void MainProcessDirector::startProcess()
{
	ui_->mainloop();
}