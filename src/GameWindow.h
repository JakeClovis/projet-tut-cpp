#ifndef _BOMBERMAN_GAME_WINDOW_H_
#define _BOMBERMAN_GAME_WINDOW_H_

#include "Globals.h"

using namespace std;

/*! \brief The main window, contains general display informations
 */
class GameWindow : public sf::RenderWindow
{
private:

	int m_tileSize; //!< regular size of a square tile, it's the main unit used for the display
	int m_width, m_height; //!< width and height of the window in terms of Tiles
	bool m_toRectifyRatio; //!< technical boolean used to manage the ratio of the window

public:

	/*! \brief creates a window with the default tile size (DEFAULT_TILE_SIZE as defined in Global.h)
	 *  \param width width in terms of Tiles
	 *  \param height height in terms of Tiles
	 */
	void create(int width, int height);
	/*! \brief creates a window with a custom tile size
	 *  \param the custom tile size
	 *  \param width width in terms of Tiles
	 *  \param height height in terms of Tiles
	 */
	void create(int tileSize, int width, int height);
	/*! \brief getter of m_tileSize
	 *  \return m_tileSize
	 */
	int getTileSize();
	/*! \brief getter of m_width
	 *  \return m_width
	 */
	int getWidth();
	/*! \brief getter of m_height
	 *  \return m_height
	 */
	int getHeight();
	/*! \brief modifies the ratio to correspond to m_width:m_height whenever it's needed
	 */
	void rectifyRatio();
	/*! \brief executes actions based on the sf::Event in parameter
	 *  \param event the event to use
	 */
	void manageEvents(sf::Event &event);
};

#endif //_BOMBERMAN_GAME_WINDOW_H_
