#include "MapTile.h"

MapTile::MapTile(TileType type): Tile(type)
{
}

MapTile::MapTile(sf::Sprite &s, TileType type): Tile(s, type)
{
}

void MapTile::setCollidable(bool c)
{
	m_collidable = c;
}

void MapTile::setBreakable(bool b)
{
	m_breakable = b;
}

bool MapTile::isCollidable()
{
	return m_collidable;
}

bool MapTile::isBreakable()
{
	return m_breakable;
}
