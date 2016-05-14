#ifndef _BOMBERMAN_PLAYER_H_
#define _BOMBERMAN_PLAYER_H_

#include "Globals.h"
#include "LivingEntity.h"
#include "IHandlable.h"
#include "GameWindow.h"

/*! \brief un joueur est une entité vivante controlable
 */
class Player: public LivingEntity, public IHandlable
{
protected:

	unsigned int m_blastPower;  //!< La puissance des bombes que pose le joueur
	unsigned int m_bombCount; //!< Le nombre de bombes qu'un joueur peut poser simultanément
	vector<sf::Keyboard::Key> m_controls; //!< Les contrôles du joueur, dans l'ordre : Haut, Droite, Bas, Gauche, Poser bombe

public:

	/*! \brief crée un joueur
	 *  \see LivingEntity::LivingEntity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health)
	 */
	Player(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health, vector<sf::Keyboard::Key> controls);
	virtual void manageEvents(sf::Event &event, void *args=NULL);

};

#endif //_BOMBERMAN_PLAYER_H_
