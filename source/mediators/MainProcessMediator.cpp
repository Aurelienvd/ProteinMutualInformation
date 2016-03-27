#include "MainProcessMediator.hpp"

MainProcessMediator::MainProcessMediator(): ui_(nullptr), data_manager_(nullptr), protein_adt_(nullptr) 
{
	createColleagues();
}

MainProcessMediator::~MainProcessMediator()
{
	delete ui_;
	delete data_manager_;
	delete protein_adt_;
}

void MainProcessMediator::createColleagues()
{
	ui_ = new UI(this);
	data_manager_ = new DataManager(this);
	protein_adt_ = new ProteinData(this);
}

void MainProcessMediator::colleagueJobDone(Facade* facade)
{
	if (facade == ui_){

	} else if (facade == data_manager_){

	} else if (facade == protein_adt_){

	}
}