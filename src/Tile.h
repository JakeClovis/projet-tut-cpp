#ifndef _BOMBERMAN_TILE_H_
#define _BOMBERMAN_TILE_H_

#include "Globals.h"

class Tile
{
private:	
	
	vector<sf::Sprite*> m_sprites;

public:

	Tile(sf::Sprite&); // default constructor which adds a first sprite to the Tile
	Tile(); // empty constructor
	~Tile(); // destructor
	void addSprite(sf::Sprite&); // adds another sprite to the tile
	sf::Sprite *getSprite(float, float); // gets the first sprite of the vector of sprites at the given coordinates (useful for a monosprite tile)
	sf::Sprite *getSprite(unsigned int, float, float); // gets the sprite at given index, at given coordinates (useful for a multisprite tile)
};

#endif //_BOMBERMAN_TILE_H_
