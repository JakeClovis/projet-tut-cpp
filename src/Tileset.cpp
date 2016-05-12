#include "Tileset.h"

Tileset::Tileset(const sf::Texture *tex, 
				int rows, int cols, 
				int width, int height, 
				int displayWidth, int displayHeight): 
		m_texture(tex), m_rows(rows), m_cols(cols), m_width(width), m_height(height), m_displayWidth(displayWidth), m_displayHeight(displayHeight)
{
	cout << "** Creating the Tileset " << this << " with the texture " << tex << endl;
}

template<>
MapTile *Tileset::createTile<MapTile>(int i, int j, TileType ty, bool c, bool b)
{
	MapTile *t = (MapTile *) createTile(i, j, ty);
	t->setCollidable(c);
	t->setBreakable(b);
	return t;
}

template<>
MapTile *Tileset::createTile<MapTile>(vector<int> i, vector<int> j, TileType ty, bool c, bool b)
{
	MapTile *t = (MapTile *) createTile(i, j, ty);
	t->setCollidable(c);
	t->setBreakable(b);
	return t;
}

const sf::Texture *Tileset::getTexture()
{
	return m_texture;
}

int Tileset::getDisplayWidth()
{
	return m_displayWidth;
}

int Tileset::getDisplayHeight()
{
	return m_displayHeight;
}

int Tileset::getWidth()
{
	return m_width;
}

int Tileset::getHeight()
{
	return m_height;
}

int Tileset::getRows()
{
	return m_rows;
}

int Tileset::getCols()
{
	return m_cols;
}

