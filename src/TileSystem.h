#ifndef _BOMBERMAN_TILE_SYSTEM_H_
#define _BOMBERMAN_TILE_SYSTEM_H_

#include "Globals.h"
#include "Tileset.h"
#include "Tile.h"

/*! \brief un système de tuiles lie les données brutes d'un Tileset avec tous les Tile extraits de ce Tileset
 */
class TileSystem
{
private:

	Tileset *m_ts; //!< Tileset utilisé par le système
	map<unsigned int, Tile*> m_tilesList; //!< liste de toutes les tuiles déclarées

public:

	/*! \brief crée un système de tuiles
	 *  \param ts le Tileset à utiliser
	 */
	TileSystem(Tileset *ts);
	/*! \brief détruit le système de tuiles
	 *
	 *  Désallouera tous les Tiles.
	 */
	virtual ~TileSystem();

	template<typename T = Tile>
	/*! \brief indexe un Tile mono-sprite
	 *  \param index indice du Tile
	 *  \param i abscisse du sprite dans le Tileset
	 *  \param j ordonnée du sprite dans le Tileset
	 *  \param ty le type de tuile
	 *  \param c vrai si la tuile est physique (n'aura aucun effet si on ne crée pas une tuile MapTile)
	 *  \param b vrai si la tuile est destructible (n'aura aucun effet si on ne crée pas une tuile MapTile)
	 */
	void registerTile(unsigned int index, int i, int j, TileType ty=TileType::DEFAULT, bool c=NULL, bool b=NULL)
	{
		T *t = m_ts->createTile<T>(i, j, ty);
		if(index != 0)
		{
			cout << "** Registering the Tile " << t << " in the TileSystem " << this << endl;
			if(m_tilesList.insert(pair<unsigned int, Tile*>(index, (Tile*) t)).second == false)
				cout << "(!)WARNING:" << index << " is an already existing index in the TileSystem " << this << " (insertion of " << t << " ommitted)" << endl;
		}
		else
			cout << "(!)WARNING:couldn't register " << t << " in the TileSystem " << this << " (0 is a special index)" << endl;
	}

	template<typename T = Tile>
	/*! \brief indexe un Tile multi-sprite
	 *  \param index indice du Tile
	 *  \param i abscisses des sprites dans le Tileset
	 *  \param j ordonnée des sprites dans le Tileset
	 *  \param ty le type de tuile
	 *  \param c vrai si la tuile est physique (n'aura aucun effet si on ne crée pas une tuile MapTile)
	 *  \param b vrai si la tuile est destructible (n'aura aucun effet si on ne crée pas une tuile MapTile)
	 */
	void registerTile(unsigned int index, vector<int> i, vector<int> j, TileType ty=TileType::DEFAULT, bool c=NULL, bool b=NULL)
	{
		T *t = m_ts->createTile<T>(i, j, ty);
		if(index != 0)
		{
			cout << "** Registering the Tile " << t << " in the TileSystem " << this << endl;
			if(m_tilesList.insert(pair<unsigned int, Tile*>(index, (Tile*) t)).second == false)
				cout << "(!)WARNING:" << index << " is an already existing index in the TileSystem " << this << " (insertion of " << t << " ommitted)" << endl;
		}
		else
			cout << "(!)WARNING:couldn't register " << t << " in the TileSystem " << this << " (0 is a special index)" << endl;
	}

	/*! \brief retourne le Tile d'indice donné
	 *  \param index indice du Tile
	 *  \return pointeur sur le Tile
	 */
	Tile *getTile(unsigned int index);
	/*! \brief accesseur de m_ts
	 *  \returns m_ts
	 */
	Tileset *getTs();
	/*! \brief nombre de Tile indexés
	 *  \return taille de m_tilesList
	 */
	int getSize();
};

#endif //_BOMBERMAN_TILE_SYSTEM_H_
