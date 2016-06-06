#ifndef _BOMBERMAN_TILESET_H_
#define _BOMBERMAN_TILESET_H_

#include "Globals.h"
#include "MapTile.h"
#include "Tile.h"

/*! \brief un set de tuiles stocke des informations brutes à propos d'une texture de tuiles
 */
class Tileset
{
private:

	const sf::Texture *m_texture; //!< la texture du set de tuiles
	int m_rows; //!< nombre de lignes dans la texture
	int m_cols; //!< nombre de colonnes dans la texture
	int m_width; //!< largeur d'une tuile dans la texture
	int m_height; //!< hauteur d'une tuile dans la texture
	int m_displayWidth; //!< largeur d'affichage d'une tuile
	int m_displayHeight; //!< hauteur d'affichage d'une tuile

public:

	/*! \brief crée un set de tuiles avec les paramètres donnés
	 *  \param tex texture à utiliser
	 *  \param rows nombre de lignes
	 *  \param cols nombre de colonnes
	 *  \param width largeur d'une tuile
	 *  \param height hauteur d'une tuile
	 *  \param displayWidth largeur d'affichage d'une tuile
	 *  \param displayHeight hauteur d'affichage d'une tuile
	 */
	Tileset(const sf::Texture *tex, int rows, int cols, int width, int height, int displayWidth, int displayHeight);

	template<typename T = Tile>
	/*! \brief crée une tuile avec seulement un sprite dedans
	 *  \param i abscisse (en termes de colonnes de tuiles)
	 *  \param j ordonnée (en termes de colonnes de tuiles)
	 *  \param ty le type de tuile
	 *  \param c vrai si la tuile est physique (n'aura aucun effet si on ne crée pas une tuile MapTile)
	 *  \param b vrai si la tuile est destructible (n'aura aucun effet si on ne crée pas une tuile MapTile)
	 */
	T *createTile(int i, int j, TileType ty=TileType::DEFAULT, bool c=false, bool b=false)
	{
		sf::Sprite *newSprite = new sf::Sprite();
		cout << "** Setting up the sf::Sprite " << newSprite << " via Tileset " << this << endl;
		newSprite->setTexture(*m_texture);
		newSprite->setTextureRect(sf::IntRect(
								(i-1)*m_width,
								(j-1)*m_height,
								m_width,
								m_height));
		newSprite->setScale((float)m_displayWidth/(float)m_width,
						(float)m_displayHeight/(float)m_height);
		return new T(*newSprite, ty);
	}
	
	template<typename T = Tile>
	/*! \brief crée une tuile avec de multiples sprites dedans
	 *  \param i abscisses (en termes de colonnes de tuiles)
	 *  \param j ordonnées (en termes de colonnes de tuiles)
	 *  \param ty le type de tuile
	 *  \param c vrai si la tuile est physique (n'aura aucun effet si on ne crée pas une tuile MapTile)
	 *  \param b vrai si la tuile est destructible (n'aura aucun effet si on ne crée pas une tuile MapTile)
	 */
	T *createTile(vector<int> i,vector <int> j, TileType ty=TileType::DEFAULT, bool c=false, bool b=false)
	{
		T *t = new T(ty);
		sf::Sprite *newSprite = NULL;
		for(unsigned int k = 0 ; (k < i.size()) && (k < j.size()) ; k++)
		{
			newSprite = new sf::Sprite();
			cout << "** Setting up the sf::Sprite " << newSprite << " via Tileset " << this << endl;
			newSprite->setTexture(*m_texture);
			newSprite->setTextureRect(sf::IntRect(
									(i[k]-1)*m_width,
									(j[k]-1)*m_height,
									m_width,
									m_height));
			newSprite->setScale((float)m_displayWidth/(float)m_width,
							(float)m_displayHeight/(float)m_height);
			t->addSprite(*newSprite);
		}

		return t;
	}

	/*! \brief accesseur de m_texture
	 *  \return m_texture
	 */
	const sf::Texture *getTexture();
	/*! \brief accesseur de m_displayWidth
	 *  \return m_displayWidth
	 */
	int getDisplayWidth();
	/*! \brief accesseur de m_displayHeight
	 *  \return m_displayHeight
	 */
	int getDisplayHeight();
	/*! \brief accesseur de m_width
	 *  \return m_width
	 */
	int getWidth();
	/*! \brief accesseur de m_height
	 *  \return m_height
	 */
	int getHeight();
	/*! \brief accesseur de m_rows
	 *  \return m_rows
	 */
	int getRows();
	/*! \brief accesseur de m_cols
	 *  \return m_cols
	 */
	int getCols();
};

#endif //_BOMBERMAN_TILESET_H_
