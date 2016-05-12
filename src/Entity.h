#ifndef _BOMBERMAN_ENTITY_H_
#define _BOMBERMAN_ENTITY_H_

#include "Globals.h"
#include "IDrawable.h"
#include "TileSystem.h"
#include "Tilemap.h"

enum Orientation { TOP=1, RIGHT=2, BOTTOM=3, LEFT=4 };

class Entity: public IDrawable
{
protected:

	sf::Clock m_watcher;
	int m_tick;	
	int m_health;
	int m_maxHealth;
	sf::Vector2f m_position;
	sf::Vector2f m_center;
	map<Orientation, sf::IntRect> m_bBoxes;

public:

	Entity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health);
	virtual ~Entity();
	virtual void updateState(sf::Time &elapsed, Tilemap *world) = 0;
};

#endif //_BOMBERMAN_ENTITY_H_
