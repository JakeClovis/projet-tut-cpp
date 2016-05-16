#ifndef _BOMBERMAN_PLAYER_H_
#define _BOMBERMAN_PLAYER_H_

#include "Globals.h"
#include "LivingEntity.h"
#include "IHandlable.h"
#include "Tilemap.h"
#include "Bomb.h"
#include "GameWindow.h"


/*! \brief un joueur est une entité vivante controlable
 */
class Player: public LivingEntity, public IHandlable
{
protected:

	unsigned int m_blastPower;  //!< La puissance des bombes que pose le joueur
	unsigned int m_bombCount; //!< Le nombre de bombes qu'un joueur peut poser simultanément
	unsigned int m_bombInventory; //!< Le nombre de bombes que le joueur peut encore poser
	bool m_bombHasBeenDropped; //!< boolean permettant d'éviter que plusieurs bombes soient posées par un même appui sur la touche de drop
	TileSystem *m_bombTilesys; //!< le TileSystem des bombes que le joueur pose
	vector<sf::Keyboard::Key> m_controls; //!< Les contrôles du joueur, dans l'ordre : Haut, Droite, Bas, Gauche, Poser bombe
	/*! \brief crée une bombe aux coordonnées indiquées, si possible
	 *  \param pos position sur la map où larguer la bombe
	 *  \param list registre d'entités sur lequel inscrire la bombe
	 */
	void dropBomb(sf::Vector2f pos, vector<Entity*> *list);

public:

	/*! \brief crée un joueur
	 *  \see LivingEntity::LivingEntity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health)
	 */
	Player(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health, vector<sf::Keyboard::Key> controls, TileSystem *bombTilesys);
	void manageEvents(sf::Event &event, void *args=NULL);
	/*! \brief doit être appelé par la bombe d'un joueur quand elle explose, pour notifier ce dernier qu'elle a explosée
	 */
	void notifyExplosion();

};

#endif //_BOMBERMAN_PLAYER_H_
