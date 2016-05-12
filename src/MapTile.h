#ifndef _BOMBERMAN_MAP_TILE_H_
#define _BOMBERMAN_MAP_TILE_H_

#include "Globals.h"
#include "Tile.h"

/*! \brief Stocke les données relatives à un Tile de Tilemap
 */
class MapTile: public Tile
{
protected:
	
	bool m_collidable; //!< vrai si le Tile est physique
	bool m_breakable; //!< vrai si le Tile est cassable

public:

	/*! \brief crée un MapTile avec un premier sf::Sprite
	 *  \param s premier sf::Sprite du MapTile
	 *  \param type le type de tile
	 */
	MapTile(sf::Sprite &s, TileType type=TileType::DEFAULT);
	/*! \brief crée un MapTile sans sf::Sprite
	 *  \param type le type de tile
	 */
	MapTile(TileType type=TileType::DEFAULT);
	/*! \brief mutateur de m_collidable
	 *  \param c nouvelle valeur de m_collidable
	 */
	void setCollidable(bool c);
	/*! \brief mutateur de m_breakable
	 *  \param b nouvelle valeur de m_breakable
	 */
	void setBreakable(bool b);
	/*! \brief accesseur de m_collidable
	 *  \return m_collidable
	 */
	bool isCollidable();
	/*! \brief accesseur de m_breakable
	 *  \return m_breakable
	 */
	bool isBreakable();
};

#endif //_BOMBERMAN_MAP_TILE_H_
