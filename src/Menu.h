#ifndef _BOMBERMAN_MENU_H_
#define _BOMBERMAN_MENU_H_

#include "Globals.h"
#include "Controller.h"
#include "Game.h"
#include "Button.h"

/*! \brief contrôleur qui gère le menu principal
 */
class Menu: public Controller
{
private:

	/*! \brief appelé durant la boucle principale
	 *
	 * La gestion des évènements du menu comprend la vérification du clic.
	 */
	void manageEvents();
	Button *playButton; //!< bouton Jouer
	Button *quitButton; //!< bouton quitter
	sf::Sprite background; //!< image d'arrière plan
	sf::Sprite logo; //!< logo du jeu
	
public:

	/*! \brief crée un contrôleur de menu
	 *  \see Controller::Controller(GameWindow *window)
	 */
	Menu(GameWindow* window);
	/*! \brief met fin au contrôleur du menu
	 *  \see Controller::~Controller()
	 */
	virtual ~Menu();
	/*! \brief méthode principale qui gère la vie du menu
	 *  \see void Controller::start()
	 */
	void start();
};

#endif //_BOMBERMAN_MENU_H_
