#ifndef _BOMBERMAN_GAME_H_
#define _BOMBERMAN_GAME_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameWindow.h"

#define DEFAULT_TILE_SIZE 70

using namespace std;

class Game
{
private:
	
	GameWindow m_window; // main window
	int m_tileSize; //real size of a tile (in pixels)

public:

	Game(); // empty constructor
	Game(int); // default constructor
	void start(); // launches the game with the defined configuration
};

#endif //_BOMBERMAN_GAME_H_
