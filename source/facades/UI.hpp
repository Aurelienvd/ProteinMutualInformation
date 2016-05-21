
/**
 * A facade that interacts with a user. As for now, the ui is a terminal but it can be extended to GUI with small changes.
 */

#ifndef __UI_HPP
#define __UI_HPP

#include <memory>

#include "Facade.hpp"
#include "../ui/MainMenu.hpp"

class UI : public Facade {

	private:

		//-----------------------
		// Private data members
		//-----------------------
		//
		// menu_
		//		A pointer to the what the user will see, the concrete user interface class.
		//
		// request_
		//		A pointer to a user request.

		std::unique_ptr<MainMenu> menu_;
		std::shared_ptr<UserRequest> request_;

	public:

		/** @name Constructors */
		//@{
		/** The default constructor.
		 *
		 * @see Facade
		 */
		//@}

		UI(ProcessDirector* director);
		virtual ~UI() = default;

		/**
		 * Override the parent's method.
		 *
		 * @see Facade
		 */

		void jobDone();

		/**
		 * Start the mainloop of the UI process.
		 */

		void mainloop();

		/**
		 * Set the request of the user after an user interface interaction.
		 *
		 * @param A pointer to the request.
		 */

		void setRequest(std::shared_ptr<UserRequest> request);

		/**
		 * Get the request of the user
		 *
		 * @return The user request.
		 *
		 */

		std::shared_ptr<UserRequest> getRequest() const;

		/**
		 * Display a message.
		 *
		 * This method is used by backends objects to display progress to the user.
		 *
		 * @param The message to display
		 *
		 * @see MainMenu
		 */

		void displayMessage(std::string msg) const;

};

#endif /* __UI_HPP */