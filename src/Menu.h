#ifndef _BOMBERMAN_MENU_H_
#define _BOMBERMAN_MENU_H_

#include "Globals.h"
#include "Controller.h"
#include "Game.h"
#include "Button.h"

class Menu: public Controller
{
private:

	void manageEvents();
	Button *playButton, *quitButton;
	sf::Sprite background, logo;
	
public:

	Menu(GameWindow*);
	virtual ~Menu();
	void start();
};

#endif //_BOMBERMAN_MENU_H_
