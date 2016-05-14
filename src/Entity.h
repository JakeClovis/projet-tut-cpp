#ifndef _BOMBERMAN_ENTITY_H_
#define _BOMBERMAN_ENTITY_H_

#include "Globals.h"
#include "IDrawable.h"
#include "TileSystem.h"
#include "Tilemap.h"

/*! \brief Base abstraite des entités du jeu
 *  
 *  Une entité est un IDrawable potentiellement évolutif : il s'affiche sur la TileMap et peut se mouvoir, mourir ou agir dessus.
 */
class Entity: public IDrawable
{
protected:

	sf::Clock m_watcher; //!< cette horloge permet de gérer la mise à jour du tick
	int m_tick;	//!< valeur particulière qui permet de gérer un état générique de l'entité (son animation par exemple)
	int m_health; //!< la santé d'une entité peut avoir de multiples utilités : typiquement une vie <=0 signifie que l'entité est morte, et nécessite un traitement particulier
	int m_maxHealth; //!< la santé maximale d'un tick
	sf::Vector2f m_position; //!< position de l'entité
	sf::Vector2f m_center; //!< centre d'affichage de l'entité par rapport au coin supérieur gauche du Tile
	map<Orientation, sf::IntRect> m_bBoxes; //!< boite de collision de chaque orientation (il n'y en a qu'une si l'entité n'est pas vivante)

public:

	/*! \brief crée une entité
	 *
	 *  \param tilesys TileSystem de l'entité
	 *  \param bBoxes boites de collision
	 *  \param center le centre d'affichage de l'entité
	 *  \param position position initiale de l'entité
	 *  \param health santé maximale (et initiale) de l'entité
	 */
	Entity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health);
	virtual ~Entity();
	/*! \brief met à jour l'état de l'entité en fonction du temps écoulé
	 *  
	 *  \param elapsed temps écoulé
	 *  \param world le monde dans lequel évolue l'entité
	 */
	virtual void updateState(sf::Time &elapsed, Tilemap *world) = 0;
};

#endif //_BOMBERMAN_ENTITY_H_
