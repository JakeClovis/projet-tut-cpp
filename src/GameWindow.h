#ifndef _BOMBERMAN_GAME_WINDOW_H_
#define _BOMBERMAN_GAME_WINDOW_H_

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class GameWindow : public sf::RenderWindow
{
	public:
		void create(int, int);
};

#endif //_BOMBERMAN_GAME_WINDOW_H_
