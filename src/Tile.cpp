#include "Tile.h"

Tile::Tile(sf::Sprite &s)
{
	cout << "** Creating the Tile " << this << " with the sprite " << &s << endl;
	m_sprites.push_back(&s);
}

Tile::Tile()
{
	cout << "** Creating the Tile " << this << " with no sprite in it" << endl;
}

void Tile::addSprite(sf::Sprite &s)
{
	cout << "** Adding to the Tile " << this << " the sprite " << &s << endl;
	m_sprites.push_back(&s);
}

sf::Sprite *Tile::getSprite(float x, float y)
{
	if(m_sprites.size() > 0)
	{
		m_sprites[0]->setPosition(sf::Vector2f(x, y));
		return m_sprites[0];
	}
	else
		return NULL;
}

sf::Sprite *Tile::getSprite(unsigned int index, float x, float y)
{
	if((index < m_sprites.size()) && (index >= 0))
	{
		m_sprites[index]->setPosition(sf::Vector2f(x, y));
		return m_sprites[index];
	}
	else
		return NULL;
}


Tile::~Tile()
{
	cout << "** Deleting the Tile " << this << endl;
	for(unsigned int i = 0 ; i < m_sprites.size() ; i++)
	{
		cout << " * Deallocating the Sprite " << m_sprites[i] << endl;
		delete m_sprites[i];
	}
}
