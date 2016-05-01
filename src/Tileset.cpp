#include "Tileset.h"

Tileset::Tileset(const sf::Texture *tex, 
				int rows, int cols, 
				int width, int height, 
				int displayWidth, int displayHeight): 
		m_texture(tex), m_rows(rows), m_cols(cols), m_width(width), m_height(height), m_displayWidth(displayWidth), m_displayHeight(displayHeight)
{
	cout << "** Creating the Tileset " << this << " with the texture " << tex << endl;
}

Tile *Tileset::createTile(int i, int j)
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

	return new Tile(*newSprite);
}

Tile *Tileset::createTile(vector<int> i,vector <int> j)
{
	Tile *t = new Tile();
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

const sf::Texture *Tileset::getTexture()
{
	return m_texture;
}

int Tileset::getDisplayWidth()
{
	return m_displayWidth;
}

int Tileset::getDisplayHeight()
{
	return m_displayHeight;
}

int Tileset::getWidth()
{
	return m_width;
}

int Tileset::getHeight()
{
	return m_height;
}

int Tileset::getRows()
{
	return m_rows;
}

int Tileset::getCols()
{
	return m_cols;
}

