#ifndef _BOMBERMAN_CONTROLLER_H_
#define _BOMBERMAN_CONTROLLER_H_

#include <SFML/Audio.hpp>

#include "Globals.h"
#include "GameWindow.h"
#include "Tileset.h"
#include "TileSystem.h"

class Controller
{
protected:

	GameWindow *m_window;
	map<string, sf::Texture*> m_textures;
	map<string, sf::Font*> m_fonts;
	map<string, Tileset*> m_tilesets;
	map<string, TileSystem*> m_tilesystems;
	map<string, sf::Music*> m_musics;
	bool m_toRectifyRatio;
	virtual void manageEvents() = 0;

public:

	Controller(GameWindow*);
	virtual ~Controller();
	virtual void start() = 0;
};

#endif //_BOMBERMAN_CONTROLLER_H_
