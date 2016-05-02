#ifndef _BOMBERMAN_TILE_SYSTEM_H_
#define _BOMBERMAN_TILE_SYSTEM_H_

#include "Globals.h"
#include "Tileset.h"
#include "Tile.h"

class TileSystem
{
private:

	Tileset *m_ts; 
	map<unsigned int, Tile*> m_tilesList;

public:

	TileSystem(Tileset*); // default constructor
	
	Tileset *getTs(); // gets the pointer on the Tileset
};
