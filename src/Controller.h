#ifndef _BOMBERMAN_CONTROLLER_H_
#define _BOMBERMAN_CONTROLLER_H_

#include <SFML/Audio.hpp>

#include "Globals.h"
#include "GameWindow.h"
#include "Tileset.h"
#include "TileSystem.h"
#include "ResourceAllocator.h"

/*! \brief Abstract class for the controllers of the game
 */
class Controller
{
protected:

	GameWindow *m_window; //!< pointer to the GameWindow that the Controller manages
	map<string, sf::Texture*> m_textures; //!< a referenced list of sf::texture handled by the controller
	map<string, sf::Font*> m_fonts; //!< a referenced list of sf::Texture handled by the controller
	map<string, Tileset*> m_tilesets; //!< a referenced list of Tileset handled by the controller
	map<string, TileSystem*> m_tilesystems; //!< a referenced list of TileSystem handled by the controller
	map<string, sf::Music*> m_musics; //!< a referenced list of sf::Music handled by the controller
	/*! \brief called during the event management
	 */
	virtual void manageEvents() = 0;

public:

	/*! \brief default constructor
	 *
	 *  Creates all the resources the Controller needs.
	 *  \param pointer to the GameWindow that the Controller will manage
	 */
	Controller(GameWindow *window);
	/*! \brief destructor
	 *
	 *  Deallocates all the referenced lists of the Controller.
	 */
	virtual ~Controller();
	/*! \brief starts the Controller
	 *
	 *  This method contains the event loop of the GameWindow, so this method will only stops when the Controller must die.
	 */
	virtual void start() = 0;
};

#endif //_BOMBERMAN_CONTROLLER_H_
