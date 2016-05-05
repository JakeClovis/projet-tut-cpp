#ifndef _BOMBERMAN_GAME_H_
#define _BOMBERMAN_GAME_H_

#include "Globals.h"
#include "ResourceAllocator.h"
#include "GameWindow.h"
#include "TileSystem.h"
#include "Tilemap.h"
#include "Controller.h"

class Game: public Controller
{
private:
	
	sf::View m_view;
	map<string, Tileset*> m_tilesets;
	void manageEvents();

public:

	Game(GameWindow*);
	virtual ~Game(); // destructor
	void start();
};

#endif //_BOMBERMAN_GAME_H_
