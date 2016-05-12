#ifndef _BOMBERMAN_LIVING_ENTITY_H_
#define _BOMBERMAN_LIVING_ENTITY_H_

#include "Globals.h"
#include "Entity.h"

class LivingEntity: public Entity
{
protected:
	
	sf::Vector2f m_speed;
	Orientation m_orientation;
	void move(sf::Vector2f potential, Tilemap *world);

public:

	LivingEntity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health);
	void setSpeed(sf::Vector2f speed);
	void updateState(sf::Time &elapsed, Tilemap *world);
	void draw(GameWindow* window);
};

#endif //_BOMBERMAN_LIVING_ENTITY_H_
