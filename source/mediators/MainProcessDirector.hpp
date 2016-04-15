
/**
 * A mediator class that manages the main process of the program.
 *
 * A MainProcessDirector will direct the I/O operations, the ADT creation, the UI interactions and the information algorithms.
 */


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

		//-----------------------
		// Private data members
		//-----------------------
		//
		// ui_
		//		see UI Facade
		//
		// data_manager_
		//		see DataManager Facade
		//
		// protein_adt_
		//		see ProteinData Facade
		//
		// adt_
		//		see ProteinsContainer ADT
		//
		// calculator_
		//		see InformationCalculator Facade

		UI* ui_;
		DataManager* data_manager_;
		ProteinData* protein_adt_;
		ProteinsContainer* adt_;
		InformationCalculator* calculator_;

		/**
		 * Manage when the job of the UI module is done.
		 *
		 * @see UI#jodDone
		 */

		void manageUIJobDone();
		
		/**
		 * Direct a Load Request from the UI Facade.
		 *
		 * @param The request Data.
		 *
		 * @see RequestData
		 */

		void directLoadRequest(RequestData* request_data);

		/**
		 * Direct a Save Request from the UI Facade.
		 *
		 * @param The request Data.
		 *
		 * @see RequestData
		 */

		void directSaveRequest(RequestData* request_data);

		/**
		 * Direct a Save Request from the UI Facade.
		 *
		 * @param The request Data.
		 *
		 * @see RequestData
		 */

		void directStartRequest(RequestData* request_data);

	protected:

		/**
		 * Create Colleagues.
		 *
		 * @see ProcessDirector#createColleagues
		 */

		void createColleagues();

	public:

		MainProcessDirector();
		virtual ~MainProcessDirector();

		/**
		 * Call the next of the process when a colleague's job is done.
		 *
		 * @param facade The colleague that just finished it's job.
		 */

		void colleagueJobDone(Facade* facade);

		/**
		 * Start the process by calling the first colleague's job that has to be done.
		 */

		void startProcess();

};

#endif /* __MAIN_PROCESS_DIRECTOR_HPP */