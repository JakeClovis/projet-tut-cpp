#ifndef _BOMBERMAN_GAME_WINDOW_H_
#define _BOMBERMAN_GAME_WINDOW_H_

#include "Globals.h"

using namespace std;

/*! \brief vue principale du jeu
 *
 *  Une vue est la partie affichage du modèle MVC. Elle présente à l'écran tout ce que l'utilisateur doit voir.
 */
class GameWindow : public sf::RenderWindow
{
private:

	int m_tileSize; //!< unité principale d'affichage, la taille régulière d'un tile carré classique
	int m_width, //!< largeur en m_tileSize de la fenêtre
		m_height; //!< hauteur en m_tileSize de la fenêtre
	bool m_toRectifyRatio; //!< booléen technique utilisé pour savoir si une rectification du ratio est nécessaire

public:

	/*! \brief crée une fenêtre avec la taille par défaut (DEFAULT_TILE_SIZE tel que défini dans Global.h)
	 *  \param width largeur
	 *  \param height hauteur
	 */
	void create(int width, int height);
	/*! \brief crée une fenêtre avec une taille de tile personnalisée
	 *  \param tileSize taille de tile personnalisée
	 *  \param width largeur
	 *  \param height hauteur
	 */
	void create(int tileSize, int width, int height);
	/*! \brief accesseur de m_tileSize
	 *  \return m_tileSize
	 */
	int getTileSize();
	/*! \brief accesseur de m_width
	 *  \return m_width
	 */
	int getWidth();
	/*! \brief accesseur de m_height
	 *  \return m_height
	 */
	int getHeight();
	/*! \brief rectifie le ratio à m_width:m_height
	 */
	void rectifyRatio();
	/*! \brief gestion d'évènements
	 *  \param event l'évènement à utiliser
	 */
	void manageEvents(sf::Event &event);
};

#endif //_BOMBERMAN_GAME_WINDOW_H_
