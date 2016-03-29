#ifndef __MAIN_PROCESS_DIRECTOR_HPP
#define __MAIN_PROCESS_DIRECTOR_HPP

#include <cstddef>

#include "ProcessDirector.hpp"
#include "../facades/UI.hpp"
#include "../facades/DataManager.hpp"
#include "../facades/ProteinData.hpp"


class MainProcessDirector: public ProcessDirector {

	private:

		typedef UserRequest::Choices Choices;

		UI* ui_;
		DataManager* data_manager_;
		ProteinData* protein_adt_;

		void manageUIJobDone() const;
		void directLoadRequest() const;
		void directSaveRequest() const;
		void directStartRequest() const;

	protected:

		void createColleagues();

	public:

		MainProcessDirector();
		virtual ~MainProcessDirector();
		void colleagueJobDone(Facade* facade);
		void startProcess();

};

#endif /* __MAIN_PROCESS_DIRECTOR_HPP */