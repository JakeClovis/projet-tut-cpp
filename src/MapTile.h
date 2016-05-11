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

	/*! \brief constructeur par défaut
	 *  \param s premier sf::Sprite du MapTile
	 */
	MapTile(sf::Sprite &s);
	/*! \brief constructeur par vide
	 */
	MapTile();
	void setCollidable(bool c);
	void setBreakable(bool b);
	bool isCollidable();
	bool isBreakable();
};

#endif //_BOMBERMAN_MAP_TILE_H_
