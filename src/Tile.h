#ifndef _BOMBERMAN_TILE_H_
#define _BOMBERMAN_TILE_H_

#include "Globals.h"

/*! \brief un tuile est une brique élémentaire de tout bon jeu 2D de base
 */
class Tile
{
protected:	
	
	vector<sf::Sprite*> m_sprites; //!< le ou les sprite(s) de la tuile (une tuile peut-être mono ou multi-sprite)
	TileType m_type; //!< le type de tuile


public:

	/*! \brief crée une tuile avec un premier sprite
	 *
	 *  Une tuile ne devrait pas être créée directement. Au lieu de ça il faut idéalement utiliser T *Tileset::createTile(int i, int j).
	 *  \param s le sprite à ajouter
	 */
	Tile(sf::Sprite &s, TileType type=TileType::DEFAULT);
	/*! \brief crée une tuile sans aucun sprite
	 *
	 *  Une tuile ne devrait pas être créée directement. Au lieu de ça il faut idéalement utiliser T *Tileset::createTile(vector<int> i, vector<int> j).
	 */
	Tile(TileType type=TileType::DEFAULT);
	/*! \brief détruit la tuile
	 *
	 * 	Il désallouera tout le tableau de sprites, soyez donc EXTRÊMEMENT prudent, n'oubliez pas que quand vous ajoutez un sprite à une tuile, il doit être utilisé uniquement dans cette tuile !
	 */
	virtual ~Tile();
	/*! \brief ajoute un nouveau sprite à la tuile
	 *  \param s le sprite qui sera ajouté
	 */
	void addSprite(sf::Sprite &s);
	/*! \brief récupère le premier sprite du tableau de sprites aux coordonnées données (utile pour les tuiles mono-sprite)
	 *
	 *  Attention : les coordonnées dépendent du sprite référencé par le pointeur retourné. De ce fait, appeler deux fois de suite cette méthode avec différentes coordonnées rendra le premier appel inutile. N'oubliez pas ceci si vous obtenez des résultats inattendus, par exemple si vous dessinez le même sprite un trouzillion de fois au même endroit !
	 *  \param x abscisse où le sprite sera dessiné
	 *  \param y ordonnée où le sprite sera dessiné
	 *  \return le sprite à dessiner
	 */
	sf::Sprite *getSprite(float x, float y); 
	/*! \brief récupère le sprite d'indice donné du tableau de sprites aux coordonnées données (utile pour les tuiles multi-sprite)
	 *
	 *  Attention : les coordonnées dépendent du sprite référencé par le pointeur retourné. De ce fait, appeler deux fois de suite cette méthode avec différentes coordonnées rendra le premier appel inutile. N'oubliez pas ceci si vous obtenez des résultats inattendus, par exemple si vous dessinez le même sprite un trouzillion de fois au même endroit !
	 *  \param index l'indice du sprite à récupérer
	 *  \param x abscisse où le sprite sera dessiné
	 *  \param y ordonnée où le sprite sera dessiné
	 *  \return le sprite à dessiner
	 */
	sf::Sprite *getSprite(unsigned int index, float x, float y);
	/*! \brief accesseur de m_type
	 *  \return m_type
	 */
	TileType getType();
	/*! \brief retourne le nombre de sprites dans la tuile
	 *  \return taille de m_sprites
	 */
	int getSpriteCount();
};

#endif //_BOMBERMAN_TILE_H_
