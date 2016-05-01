#ifndef _BOMBERMAN_TILE_H_
#define _BOMBERMAN_TILE_H_

#include "Globals.h"

class Tile
{
private:	
	
	vector<sf::Sprite*> m_sprites;

public:

	Tile(sf::Sprite&); // default constructor which adds a first sprite to the Tile
	~Tile(); // destructor
	sf::Sprite *getSprite(float, float); // gets the first sprite of the vector of sprites (useful for a monosprite tile)
};

#endif //_BOMBERMAN_TILE_H_
