#ifndef _BOMBERMAN_GAME_H_
#define _BOMBERMAN_GAME_H_

#include "Globals.h"
#include "GameWindow.h"
#include "TileSystem.h"
#include "Tilemap.h"

class Game
{
private:
	
	GameWindow m_window; // main window
	int m_tileSize; //real size of a tile (in pixels)
	sf::Texture m_texturePlayer, m_textureLevel;
	void setupResources(); //called by constructor, setups resources (textures, sounds, etc.)
	void manageEvents(); //manages events

public:

	Game(); // empty constructor
	Game(int); // default constructor
	void start(); // launches the game with the defined configuration
};

#endif //_BOMBERMAN_GAME_H_
