#ifndef _BOMBERMAN_BUTTON_H_
#define _BOMBERMAN_BUTTON_H_

#include "Globals.h"
#include "IDrawable.h"
#include <SFML/Graphics/Rect.hpp>

class Button: public sf::IntRect, public IDrawable
{
protected:

	TileSystem *m_tilesys;
	sf::Text m_text;
	void (*m_callback)(void*);

public:

	Button(int, int, TileSystem*, string, sf::Font*, void(*)(void*));
	virtual ~Button();
	void callback(void*);
	void draw(GameWindow*);
	
};

#endif //_BOMBERMAN_BUTTON_H_
