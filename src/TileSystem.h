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
	virtual ~TileSystem(); // destructor
	void registerTile(unsigned int, Tile*); // adds a Tile 
	Tile *getTile(unsigned int); // gets a Tile at given index
	Tileset *getTs(); // gets the pointer on the Tileset
};

#endif //_BOMBERMAN_TILE_SYSTEM_H_
