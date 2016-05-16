#ifndef _BOMBERMAN_GAME_H_
#define _BOMBERMAN_GAME_H_

#include "Globals.h"
#include "GameWindow.h"
#include "TileSystem.h"
#include "Tilemap.h"
#include "MapTile.h"
#include "Controller.h"
#include "Player.h"

/*! \brief contrôleur de partie
 */
class Game: public Controller
{
private:
	
	sf::View m_view; //!< conteneur du contexte de jeu
	sf::Clock m_timer; //!< permet la gestion du temps écoulé entre deux itérations de la boucle de jeu
	bool m_isPlaying; //!< permet de vérifier si la partie est en cours
	Player *m_player1, //!< le joueur 1
		   *m_player2; //!< le joueur 2
	Tilemap *m_physicalMap; //!< plateau de jeu
	vector<Entity*> m_entities; //!< entités non joueur présentes sur le plateau
	/*! \brief appelé durant la boucle de jeu
	 *
	 * La gestion des évènements du jeu comprend les entrées utilisateur, la demande de mise en pause, etc.
	 */
	void manageEvents();

public:

	/*! \brief crée une partie
	 *  \see Controller::Controller(GameWindow *window)
	 */
	Game(GameWindow *window);
	/*! \brief met fin au contrôleur de partie
	 *  \see Controller::~Controller()
	 */
	virtual ~Game();
	/*! \brief lance une partie et gère son cycle de vie
	 *  \see void Controller::start()
	 */
	void start();
	void notifyUpdate();
};

#endif //_BOMBERMAN_GAME_H_
