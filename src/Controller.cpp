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

	for (map<string, sf::Font*>::iterator element=m_fonts.begin() ; element != m_fonts.end() ; element++)
	{
		cout << " * Deallocating the font " << element->second << endl;
		delete element->second;
	}
	
	for (map<string, Tileset*>::iterator element=m_tilesets.begin() ; element != m_tilesets.end() ; element++)
	{
		cout << " * Deallocating the tileset " << element->second << endl;
		delete element->second;
	}

	for (map<string, TileSystem*>::iterator element=m_tilesystems.begin() ; element != m_tilesystems.end() ; element++)
	{
		cout << " * Deallocating the tilesystem " << element->second << endl;
		delete element->second;
	}

	for (map<string, sf::Music*>::iterator element=m_musics.begin() ; element != m_musics.end() ; element++)
	{
		cout << " * Deallocating the music " << element->second << endl;
		delete element->second;
	}
}

