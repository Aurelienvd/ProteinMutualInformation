#ifndef __MAIN_PROCESS_DIRECTOR_HPP
#define __MAIN_PROCESS_DIRECTOR_HPP

#include <cstddef>

#include "ProcessDirector.hpp"
#include "../facades/UI.hpp"
#include "../facades/DataManager.hpp"
#include "../facades/ProteinData.hpp"
#include "../facades/InformationCalculator.hpp"


class MainProcessDirector: public ProcessDirector {

	private:

		typedef UserRequest::Choices Choices;

		UI* ui_;
		DataManager* data_manager_;
		ProteinData* protein_adt_;
		ProteinsContainer* adt_;
		InformationCalculator* calculator_; 

		void manageUIJobDone();
		void directLoadRequest(RequestData* request_data);
		void directSaveRequest(RequestData* request_data);
		void directStartRequest(RequestData* request_data);

	protected:

		void createColleagues();

	public:

		MainProcessDirector();
		virtual ~MainProcessDirector();
		void colleagueJobDone(Facade* facade);
		void startProcess();

};

#endif /* __MAIN_PROCESS_DIRECTOR_HPP */