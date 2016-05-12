#include "Tilemap.h"

Tilemap::Tilemap(TileSystem *tilesys, int width, int height): IDrawable(tilesys), m_width(width), m_height(height)
{
	cout << "** Creating the Tilemap " << this << " using the TileSystem " << tilesys << endl;
}

void Tilemap::setMap(const vector<vector<unsigned int>> &map)
{
	cout << "** Setting up a new map for the Tilemap " << this << endl;

	for(unsigned int i = 0 ; i < m_map.size() ; i++)
	{
		m_map.pop_back();
	}

	for(int i = 0 ; i < m_height ; i++)
	{
		if(map[i].size() == (unsigned int) m_width)
		{
			m_map.push_back(map[i]);
		}
		else
			cout << "(!)WARNING:Incorrect width for the new map's line #" << i << " of Tilemap " << this << " (line ommitted)" << endl;
	}

	if(map.size() > (unsigned int) m_height)
		cout << "(!)WARNING:Incorrect height for the new map of Tilemap (last lines ommitted)" << this << endl;
}

int Tilemap::getWidth()
{
	return m_width;
}

int Tilemap::getHeight()
{
	return m_height;
}

sf::Vector2i Tilemap::toTileCoord(sf::Vector2f c)
{
	return sf::Vector2i(c.x/m_tilesys->getTs()->getDisplayWidth(), c.y/m_tilesys->getTs()->getDisplayHeight());
}

sf::Sprite *Tilemap::getSprite(int i, int j)
{
	return m_map[j][i]!=0?(m_tilesys->getTile(m_map[j][i])->getSprite(m_tilesys->getTs()->getDisplayWidth()*i, m_tilesys->getTs()->getDisplayHeight()*j)):NULL;
}

sf::Sprite *Tilemap::getSprite(unsigned int index, int i, int j)
{
	return m_map[j][i]!=0?(m_tilesys->getTile(m_map[j][i])->getSprite(index, m_tilesys->getTs()->getDisplayWidth()*i, m_tilesys->getTs()->getDisplayHeight()*j)):NULL;
}

Tile *Tilemap::getTile(unsigned int i, unsigned int j)
{
	if(i<(unsigned int) m_width && j<(unsigned int) m_height)
	{
		return m_map[j][i]!=0?(m_tilesys->getTile(m_map[j][i])):NULL;
	}
	else
	{
		return NULL;
	}
}

void Tilemap::draw(GameWindow *w)
{	
	for(int i = 0 ; i < m_width ; i++)
		for(int j = 0 ; j < m_height ; j++)
		{
			sf::Sprite *toDraw = getSprite(i, j);
			if(toDraw != NULL) 
				w->draw(*toDraw);
		}
}
