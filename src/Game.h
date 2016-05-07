#ifndef _BOMBERMAN_GAME_H_
#define _BOMBERMAN_GAME_H_

#include "Globals.h"
#include "GameWindow.h"
#include "TileSystem.h"
#include "Tilemap.h"
#include "Controller.h"

/*! \brief Controller that handles the game process
 */
class Game: public Controller
{
private:
	
	sf::View m_view; //!< container for the game context
	/*! \brief called during the event management
	 *
	 * It will control user inputs, pause process, etc.
	 */
	void manageEvents();

public:

	/*! \brief default constructor
	 *  \see Controller::Controller(GameWindow *window)
	 */
	Game(GameWindow *window);
	/*! \brief destructor
	 *  \see Controller::~Controller()
	 */
	virtual ~Game();
	/*! \brief main method that manages the lifecycle of the Controller
	 *  \see void Controller::start()
	 */
	void start();
};

#endif //_BOMBERMAN_GAME_H_
