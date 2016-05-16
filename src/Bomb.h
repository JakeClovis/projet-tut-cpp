#ifndef _BOMBERMAN_BOMB_H_
#define _BOMBERMAN_BOMB_H_

#include "Globals.h"
#include "Entity.h"

class Player;

/*! \brief Une bombe est l'élément central du jeu : elle explose les pierres et tue les joueurs
 */
class Bomb: public Entity
{
private:

	sf::Time m_duration; //!< temps que met la bombe pour perdre 1Pdv
	Player *m_player; //!< le joueur à l'origine de la bombe
	unsigned int m_blastRadius; //!< le rayon de la bombe
	unsigned int m_maxSize[4]; //!< décrit la taille maximale de chaque rayon selon l'environnement

public:

	/*! \brief crée une bombe
	 *  \param player joueur poseur de bombe
	 *  \param duration temps mis par la bombe pour exploser
	 *  \see Entity::Entity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health)
	 */
	Bomb(TileSystem *tilesys, sf::Vector2f center, sf::Vector2f position, int health, Player *player, sf::Time duration, unsigned int blastRadius);
	void updateState(Controller *controller, sf::Time &elapsed, Tilemap *world);
	void draw(GameWindow *window);
	/*! \brief accesseur de m_player
	 *  \return m_player
	 */
	Player *getPlayer();
};

#endif //_BOMBERMAN_BOMB_H_
