#ifndef _BOMBERMAN_TILE_SYSTEM_H_
#define _BOMBERMAN_TILE_SYSTEM_H_

#include "Globals.h"
#include "Tileset.h"
#include "Tile.h"

/*! \brief links the raw datas of a Tileset with all the Tile from this Tileset
 */
class TileSystem
{
private:

	Tileset *m_ts; //!< pointer to the Tileset used by the TileSystem
	map<unsigned int, Tile*> m_tilesList; //!< referenced list of the declared Tile

public:

	/*! \brief default constructor
	 *  \param ts pointer to the Tileset that will be used by the TileSystem
	 */
	TileSystem(Tileset *ts);
	/*! \brief destructor
	 */
	virtual ~TileSystem();
	/*! \brief registers a Tile with a single sf::Sprite in it
	 *  \param index index of the Tile in the referenced list
	 *  \param i x coordinate of the sf::Sprite in the Tileset
	 *  \param j y coordinate of the sf::Sprite in the Tileset
	 */
	void registerTile(unsigned int index, int i, int j);
	/*! \brief registers a Tile with multiple sf::Sprite in it
	 *  \param index index of the Tile in the referenced list
	 *  \param i x coordinates of the sf::Sprite in the Tileset
	 *  \param j y coordinates of the sf::Sprite in the Tileset
	 */
	void registerTile(unsigned int, vector<int> i, vector<int> j);
	/*! \brief returns a pointer to Tile at given index
	 *  \param index the index
	 *  \return pointer to Tile
	 */
	Tile *getTile(unsigned int index);
	/*! \brief get a pointer to the Tileset
	 *  \returns pointer to Tileset
	 */
	Tileset *getTs();
};

#endif //_BOMBERMAN_TILE_SYSTEM_H_
