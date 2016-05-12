#ifndef _BOMBERMAN_TILEMAP_H_
#define _BOMBERMAN_TILEMAP_H_

#include "Globals.h"
#include "TileSystem.h"
#include "IDrawable.h"

/*! \brief une carte est une grille de tuiles qui peut être dessinée 
 */
class Tilemap: public IDrawable
{
private:

	vector<vector<unsigned int>> m_map; //!< carte d'indices (0 est un indice spécial signifiant pas de tuile, n'importe quel autre entier naturel doit correspondre à un indice de tuile dans m_tilesys)
	vector<vector<int>> m_metadata; //!< meta-données de chaque tuile (doit faire la même taille que m_map)
	int m_width; //!< largeur de m_map
	int m_height; //!< hauteur de m_map

public:

	/*! \brief crée une carte vide avec une largeur et une hauteur définies
	 *  \param tilesys TileSystem utilisé par la carte
	 *  \param width largeur initiale de la carte
	 *  \param height hauteur initiale de la carte
	 */
	Tilemap(TileSystem *tilesys, int width, int height);
	/*! \brief mutateur de m_map
	 *
	 *  Cette méthode n'insérera pas de lignes plus larges que m_width, et ommettra les dernières lignes si leur nombre dépasse m_height.
	 *  \param map nouvelle valeur de m_map
	 */
	void setMap(const vector<vector<unsigned int>> &map);
	/*! \brief accesseur de m_width
	 *  \return m_width
	 */
	int getWidth();
	/*! \brief accesseur de m_height
	 *  \return m_height
	 */
	int getHeight();
	sf::Vector2i toTileCoord(sf::Vector2f c);
	/*! \brief récupère le premier sprite de la tuile aux coordonnées données
	 *  \param i abscisse
	 *  \param j ordonnée
	 */
	sf::Sprite *getSprite(int i, int j);
	/*! \brief récupère le sprite d'indice donnée de la tuile aux coordonnées données
	 *  \param index indice du sprite
	 *  \param i abscisse
	 *  \param j ordonnée
	 */
	sf::Sprite *getSprite(unsigned int index, int i, int j);
	/*! \brief récupère la tuile aux coordonnées données
	 *  \param i abscisse
	 *  \param j ordonnée
	 */
	Tile *getTile(unsigned int i, unsigned int j);
	/*! \brief récupère les méta-données aux coordonnées données
	 *  \param i abscisse
	 *  \param j ordonnée
	 */
	int getMetadata(unsigned int i, unsigned int j);
	void draw(GameWindow*);
};

#endif //_BOMBERMAN_TILE_SYSTEM_H_
