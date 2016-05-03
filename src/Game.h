#ifndef _BOMBERMAN_GAME_H_
#define _BOMBERMAN_GAME_H_

#include "Globals.h"
#include "ResourceAllocator.h"
#include "GameWindow.h"
#include "TileSystem.h"
#include "Tilemap.h"

class Game
{
private:
	
	GameWindow *m_window;
	map<string, sf::Texture*> m_textures;
	map<string, Tileset*> m_tilesets;
	void setupResources(); //called by constructor, setups resources (textures, sounds, etc.)
	void manageEvents(); //manages events

public:

	Game(GameWindow*); // empty constructor
	Game(GameWindow*, int); // default constructor
	virtual ~Game(); // destructor
	void start(); // launches the game with the defined configuration
};

#endif //_BOMBERMAN_GAME_H_
