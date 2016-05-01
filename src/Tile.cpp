#include "Tile.h"

Tile::Tile(sf::Sprite &s)
{
	cout << "** Creating the Tile " << this << " with the sprite " << &s << endl;
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

Tile::~Tile()
{
	for(unsigned int i = 0 ; i < m_sprites.size() ; i++)
		delete m_sprites[i];
	cout << "** Deallocating the Tile " << this << endl;
}
