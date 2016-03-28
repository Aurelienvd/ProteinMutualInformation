#ifndef __MAIN_PROCESS_DIRECTOR_HPP
#define __MAIN_PROCESS_DIRECTOR_HPP

#include <cstddef>

#include "ProcessDirector.hpp"
#include "../facades/UI.hpp"
#include "../facades/DataManager.hpp"
#include "../facades/ProteinData.hpp"


class MainProcessDirector: public ProcessDirector {

public:

	MainProcessDirector();
	virtual ~MainProcessDirector();
	void colleagueJobDone(Facade* facade);

protected:

	void createColleagues();

private:

	UI* ui_;
	DataManager* data_manager_;
	ProteinData* protein_adt_;

};

#endif /* __MAIN_PROCESS_DIRECTOR_HPP */