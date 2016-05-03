#include "GameWindow.h"

void GameWindow::create(int tileSize, int width, int height)
{
	m_tileSize = tileSize;
	cout << "** Creating a window with a size of " << width << "*" << height << " tiles (" << tileSize << "px)" << endl; 
	sf::RenderWindow::create(sf::VideoMode(width*tileSize, height*tileSize), string("Bomberman - v") + string(G_VERSION));
}

void GameWindow::create(int width, int height)
{
	GameWindow::create(DEFAULT_TILE_SIZE, width, height);
}

int GameWindow::getTileSize()
{
	return m_tileSize;
}
