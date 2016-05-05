#include "Controller.h"

Controller::Controller(GameWindow *window): m_window(window)
{
	cout << "** Initializating the Controller " << this << endl;
}

Controller::~Controller()
{
	for (map<string, sf::Texture*>::iterator element=m_textures.begin() ; element != m_textures.end() ; element++)
	{
		cout << " * Deallocating the texture " << element->second << endl;
		delete element->second;
	}

}

