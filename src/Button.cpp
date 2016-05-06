#include "Button.h"

Button::Button(int x, int y, TileSystem *tilesys, string text, sf::Font *font, void(*callback)(void*)):sf::IntRect(x, y, 0, 0), m_tilesys(tilesys), m_callback(callback)
{
	int i;
	sf::FloatRect textBox = m_text.getGlobalBounds();

	m_text.setString(text);
	m_text.setFont(*font);
	m_text.setCharacterSize(m_tilesys->getTs()->getDisplayWidth()/4);
	m_text.setColor(sf::Color::White);
	
	for(i = m_tilesys->getTs()->getDisplayWidth() ; i+1 < textBox.width ; i+=m_tilesys->getTs()->getDisplayWidth());
	width = i+m_tilesys->getTs()->getDisplayWidth();
	height = m_tilesys->getTs()->getDisplayHeight();
}

Button::~Button()
{
}

void Button::callback(void* args)
{
	if(m_callback != NULL) (*m_callback)(args);
}

void Button::draw(GameWindow *window)
{
	sf::Vector2i mouseLocation = sf::Mouse::getPosition(*window);
	int tileIndexToDraw = (contains(mouseLocation)?1:2);
	sf::FloatRect textBox = m_text.getGlobalBounds();
	int i;


	window->draw(*(m_tilesys->getTile(tileIndexToDraw)->getSprite(left, top)));
	for(i = m_tilesys->getTs()->getDisplayWidth() ; i+1 < textBox.width ; i+=m_tilesys->getTs()->getDisplayWidth())
		window->draw(*(m_tilesys->getTile(tileIndexToDraw)->getSprite(1, left + i, top)));
	window->draw(*(m_tilesys->getTile(tileIndexToDraw)->getSprite(2, left + i, top)));

	m_text.setPosition(left+(((i+m_tilesys->getTs()->getDisplayWidth())-textBox.width)/2), top + height/2 - textBox.height/2);
	window->draw(m_text);
}
