#ifndef _BOMBERMAN_TILESET_H_
#define _BOMBERMAN_TILESET_H_

#include "Globals.h"
#include "Tile.h"

class Tileset
{
private:
	
	const sf::Texture *m_texture;
	int m_rows, m_cols;
	int m_width, m_height;
	int m_displayWidth, m_displayHeight;

public:

	Tileset(const sf::Texture*, int, int, int, int, int, int); // default constructor
	Tile *createTile(int, int); // returns a pointer on a Tile corresponding to the sprite at given coordinates (monosprite tile)
	Tile *createTile(vector<int>, vector<int>); // returns a pointer on a Tile corresponding to the sprites at given coordinates (multisprite tile)a

	const sf::Texture *getTexture(); // returns the texture of the tileset
	int getDisplayWidth(); // returns the display width of a hypothetic tile in the tileset
	int getDisplayHeight(); // returns the display height of a hypothetic tile in the tileset
	int getWidth(); // returns the width of a hypothetic tile in the tileset
	int getHeight(); // returns the height of a hypothetic tile in the tileset
	int getRows(); // returns the number of rows in the tileset
	int getCols(); // returns the number of columns in the tileset
};

#endif //_BOMBERMAN_TILESET_H_
