#ifndef _BOMBERMAN_GAME_WINDOW_H_
#define _BOMBERMAN_GAME_WINDOW_H_

#include "Globals.h"

using namespace std;

class GameWindow : public sf::RenderWindow
{
private:

	int m_tileSize;
	int m_width, m_height;

public:

	void create(int, int);
	void create(int, int, int);
	int getTileSize();
	int getWidth();
	int getHeight();
	void rectifyRatio();
};

#endif //_BOMBERMAN_GAME_WINDOW_H_
