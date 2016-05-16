#ifndef _BOMBERMAN_LIVING_ENTITY_H_
#define _BOMBERMAN_LIVING_ENTITY_H_

#include "Globals.h"
#include "Entity.h"

/*! \brief une entité vivante peut se mouvoir, et possède une orientation
 */
class LivingEntity: public Entity
{
protected:
	
	sf::Vector2f m_speed; //!< vitesse actuelle de l'entité
	Orientation m_orientation; //!< orientation de l'entité
	/*! \brief tente le déplacement de l'entité
	 *  \param potential le vecteur de déplacement qu'on espère réaliser
	 *  \param world le monde dans lequel évolue l'entité (pour gérer les collisions)
	 */
	void move(sf::Vector2f potential, Tilemap *world);

public:

	/*! \brief crée une entité vivante
	 *  \see Entity::Entity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health)
	 */
	LivingEntity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health);
	/*! \brief mutateur de m_speed
	 *  \param speed nouvelle valeur de m_speed
	 */
	void setSpeed(sf::Vector2f speed);
	void updateState(Controller *controller, sf::Time &elapsed, Tilemap *world);
	void draw(GameWindow* window);
};

#endif //_BOMBERMAN_LIVING_ENTITY_H_
