#ifndef _BOMBERMAN_TILE_H_
#define _BOMBERMAN_TILE_H_

#include "Globals.h"

/*! \brief the Tile is an elementary block of a tilemapped game
 */
class Tile
{
protected:	
	
	vector<sf::Sprite*> m_sprites; //!< sf::Sprite of the Tile (a Tile can be multisprite or monosprite)

public:

	/*! \brief default constructor that initializes a Tile with a single sf::Sprite
	 *
	 *  It shouldn't be called directly. Instead it should be called via T *Tileset::createTile(int i, int j)
	 *  \param s the sf::Sprite that will be added
	 */
	Tile(sf::Sprite &s);
	/*! \brief empty constructor that initializes a Tile with no sf::Sprite in it
	 *
	 *  It shouldn't be called directly. Instead it should be called via T *Tileset::createTile(vector<int> i, vector<int> j)
	 */
	Tile();
	/*! \brief destructor
	 *
	 *  It will deallocates the vector of sf::Sprite, so be VERY careful, don't forget that when you add a sf::Sprite to a Tile, it should be only used in this Tile!
	 */
	virtual ~Tile();
	/*! \brief adds a new sf::Sprite to the Tile
	 *  \param s the sf::Sprite that will be added
	 */
	void addSprite(sf::Sprite &s);
	/*! \brief gets the first sf::Sprite of the vector of sf::Sprite at the given coordinates (useful for a monosprite Tile)
	 *
	 *  Attention please: the given coordinates depends of the original sf::Sprite. As this method returns a pointer, calling it twice with different coordinates will make the first call pointless. Don't forget that if you get unexpected results, for instance the same sf::Sprite drawn a trouzillion times at the same place!
	 *  \param x the x coordinate where the sf::Sprite will be drawn
	 *  \param y the y coordinate where the sf::Sprite will be drawn
	 */
	sf::Sprite *getSprite(float x, float y); 
	/*! \brief gets the sf::Sprite of the vector of sf::Sprite in the given index, at the given coordinates (useful for a multisprite Tile)
	 *
	 *  Attention please: the given coordinates depends of the original sf::Sprite. As this method returns a pointer, calling it twice with different coordinates will make the first call pointless. Don't forget that if you get unexpected results, for instance the same sf::Sprite drawn a trouzillion times at the same place!
	 *  \param index index of the sf::Sprite to get
	 *  \param x the x coordinate where the sf::Sprite will be drawn
	 *  \param y the y coordinate where the sf::Sprite will be drawn
	 */
	sf::Sprite *getSprite(unsigned int index, float x, float y);
};

#endif //_BOMBERMAN_TILE_H_
