#ifndef __MAIN_PROCESS_MEDIATOR_HPP
#define __MAIN_PROCESS_MEDIATOR_HPP

#include <cstddef>

#include "ProcessMediator.hpp"
#include "../facades/UI.hpp"
#include "../facades/DataManager.hpp"
#include "../facades/ProteinData.hpp"


class MainProcessMediator: public ProcessMediator {

public:

	MainProcessMediator();
	virtual ~MainProcessMediator();
	void colleagueJobDone(Facade* facade);

protected:

	void createColleagues();

private:

	UI* ui_;
	DataManager* data_manager_;
	ProteinData* protein_adt_;

};

#endif /* __MAIN_PROCESS_MEDIATOR_HPP */