#ifndef _BOMBERMAN_MENU_H_
#define _BOMBERMAN_MENU_H_

#include "Globals.h"
#include "Controller.h"
#include "Game.h"
#include "Button.h"

/*! \brief Controller that manages the main menu
 */
class Menu: public Controller
{
private:

	/*! \brief called during the event management
	 *
	 *  It will verify which button the mouse is hovering, and will execute the Button actions if needed.
	 */
	void manageEvents();
	Button *playButton; //!< the play button
	Button *quitButton; //!< the quit button
	sf::Sprite background; //!< background image
	sf::Sprite logo; //!< game logo
	
public:

	/*! \brief default constructor
	 *  \see Controller::Controller(GameWindow *window)
	 */
	Menu(GameWindow* window);
	/*! \brief destructor
	 *  \see Controller::~Controller()
	 */
	virtual ~Menu();
	/*! \brief main method that manages the lifecycle of the Controller
	 *  \see void Controller::start()
	 */
	void start();
};

#endif //_BOMBERMAN_MENU_H_
