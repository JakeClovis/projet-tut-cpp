#ifndef _BOMBERMAN_BUTTON_H_
#define _BOMBERMAN_BUTTON_H_

#include "Globals.h"
#include "IDrawable.h"
#include <SFML/Graphics/Rect.hpp>

/*! \brief Simple class to manage buttons
 */
class Button: public sf::IntRect, public IDrawable
{
protected:

	sf::Text m_text; //!< text displayed by the Button
	void (*m_callback)(void*); //!< pointer to the callback function

public:

	/*! \brief default constructor for Button
	 *  \param x position of the top-left corner of the Button 
	 *  \param y position of the top-left corner of the Button
	 *  \param tilesys pointer to the TileSystem that will be used by the Button
	 *  \param text the text that will be displayed by the Button
	 *  \param font pointer to the sf::Font that will be used by the Button
	 *  \param callback the callback function of the Button
	 */
	Button(TileSystem *tilesys, int x, int y, string text, sf::Font *font, void(*callback)(void*));
	virtual ~Button();
	/*! \brief dialer for the callback function
	 */
	void callback(void*);
	void draw(GameWindow*);
	
};

#endif //_BOMBERMAN_BUTTON_H_
