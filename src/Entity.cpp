#include "Entity.h"

Entity::Entity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health): IDrawable(tilesys), m_health(health), m_maxHealth(health), m_position(position), m_center(center), m_bBoxes(bBoxes)
{
	m_tick = 0;
}

Entity::~Entity()
{
}

int Entity::getHealth()
{
	return m_health;
}
