#include "GameWindow.h"

void GameWindow::create(int width, int height)
{
	cout << "** Creating a window with a size of " << width << "*" << height << "px" << endl;
	sf::RenderWindow::create(sf::VideoMode(width, height), "Bomberman");
}
