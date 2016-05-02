#ifndef _BOMBERMAN_TILEMAP_H_
#define _BOMBERMAN_TILEMAP_H_

#include "Globals.h"
#include "TileSystem.h"

class Tilemap
{
private:

	TileSystem *m_tilesys;
	vector<vector<unsigned int>> m_map;
	int m_width, m_height;

public:

	Tilemap(TileSystem*, int, int);
	void setMap(const vector<vector<unsigned int>>&);
	int getWidth();
	int getHeight();
	sf::Sprite *readPos(int, int);
	sf::Sprite *readPos(unsigned int, int, int);
};

#endif //_BOMBERMAN_TILE_SYSTEM_H_
