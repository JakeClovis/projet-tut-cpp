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
	
	template<typename T = Tile>
	T *createTile(int i, int j)
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
	
		return new T(*newSprite);
	}
	
	template<typename T = Tile>
	T *createTile(vector<int> i,vector <int> j)
	{
		T *t = new T();
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

	const sf::Texture *getTexture(); // returns the texture of the tileset
	int getDisplayWidth(); // returns the display width of a hypothetic tile in the tileset
	int getDisplayHeight(); // returns the display height of a hypothetic tile in the tileset
	int getWidth(); // returns the width of a hypothetic tile in the tileset
	int getHeight(); // returns the height of a hypothetic tile in the tileset
	int getRows(); // returns the number of rows in the tileset
	int getCols(); // returns the number of columns in the tileset
};

#endif //_BOMBERMAN_TILESET_H_
