#ifndef _BOMBERMAN_TILEMAP_H_
#define _BOMBERMAN_TILEMAP_H_

#include "Globals.h"
#include "TileSystem.h"
#include "IDrawable.h"

class Tilemap: public IDrawable
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
	sf::Sprite *getSprite(int, int);
	sf::Sprite *getSprite(unsigned int, int, int);
	void draw(GameWindow*);
};

#endif //_BOMBERMAN_TILE_SYSTEM_H_
