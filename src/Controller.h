#ifndef _BOMBERMAN_CONTROLLER_H_
#define _BOMBERMAN_CONTROLLER_H_

#include "Globals.h"
#include "GameWindow.h"

class Controller
{
protected:

	GameWindow *m_window;
	map<string, sf::Texture*> m_textures;
	bool m_toRectifyRatio;
	virtual void manageEvents() = 0;

public:

	Controller(GameWindow*);
	virtual ~Controller();
	virtual void start() = 0;
};

#endif //_BOMBERMAN_CONTROLLER_H_
