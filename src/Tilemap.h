#ifndef _BOMBERMAN_TILEMAP_H_
#define _BOMBERMAN_TILEMAP_H_

#include "Globals.h"
#include "TileSystem.h"
#include "IDrawable.h"

/*! \brief a Tilemap is a grid of Tiles
 */
class Tilemap: public IDrawable
{
private:

	TileSystem *m_tilesys; //!< pointer to the TileSystem used by the Tilemap
	vector<vector<unsigned int>> m_map; //!<  map of indexes (0 means no Tile, any other positive integer is the index of a Tile in m_tilesys)
	int m_width; //!< actual width of the m_map
	int m_height; //!< actual height of the m_map

public:

	/*! \brief default constructor
	 *  \param tilesys pointer to the TileSystem that will be used by the Tilemap
	 *  \param width initial width of the Tilemap
	 *  \param height initial height of the Tilemap
	 */
	Tilemap(TileSystem *tilesys, int width, int height);
	/*! \brief replaces the m_map with a new map
	 *
	 *  This method won't insert lines larger than m_width, and will ommit the last lines if their count overflows m_height
	 *  \param map the new map
	 */
	void setMap(const vector<vector<unsigned int>> &map);
	/*! \brief getter of m_width
	 *  \return m_width
	 */
	int getWidth();
	/*! \brief getter of m_height
	 *  \return m_height
	 */
	int getHeight();
	/*! \brief get the first sf::Sprite of the Tile at given coordinates
	 *  \param i x value
	 *  \param j y value
	 */
	sf::Sprite *getSprite(int i, int j);
	/*! \brief get the sf::Sprite of the Tile of given index, at given coordinates
	 *  \param index index of the sf::Sprite to get
	 *  \param i x value
	 *  \param j y value
	 */
	sf::Sprite *getSprite(unsigned int index, int i, int j);
	Tile *getTile(unsigned int i, unsigned int j);
	void draw(GameWindow*);
};

#endif //_BOMBERMAN_TILE_SYSTEM_H_
