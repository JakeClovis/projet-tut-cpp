#ifndef _BOMBERMAN_GAME_H_
#define _BOMBERMAN_GAME_H_

#include "Globals.h"
#include "GameWindow.h"
#include "Tileset.h"

class Game
{
private:
	
	GameWindow m_window; // main window
	int m_tileSize; //real size of a tile (in pixels)
	sf::Texture m_textureBase;
	void setupTextures(); //called by constructor, setups textures

public:

	Game(); // empty constructor
	Game(int); // default constructor
	void start(); // launches the game with the defined configuration
};

#endif //_BOMBERMAN_GAME_H_
