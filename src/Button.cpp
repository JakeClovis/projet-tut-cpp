#include "Button.h"

Button::Button(TileSystem *tilesys, int x, int y, string text, sf::Font *font, void(*callback)(void*)):sf::IntRect(x, y, 0, 0), IDrawable(tilesys), m_callback(callback)
{
	int i;

	m_text.setString(text);
	m_text.setFont(*font);
	m_text.setCharacterSize(m_tilesys->getTs()->getDisplayWidth()/3);
	m_text.setColor(sf::Color::White);
	
	sf::FloatRect textBox = m_text.getGlobalBounds();
	
	for(i = 1 ; i*m_tilesys->getTs()->getDisplayWidth() < textBox.width ; i++);
	width = (1+i)*m_tilesys->getTs()->getDisplayWidth();
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
	for(i = 1 ; (i+1)*m_tilesys->getTs()->getDisplayWidth() < width ; i++)
		window->draw(*(m_tilesys->getTile(tileIndexToDraw)->getSprite(1, left + (i*m_tilesys->getTs()->getDisplayWidth()), top)));
	window->draw(*(m_tilesys->getTile(tileIndexToDraw)->getSprite(2, left + (i*m_tilesys->getTs()->getDisplayWidth()), top)));

	m_text.setPosition(left+((((i*m_tilesys->getTs()->getDisplayWidth())+m_tilesys->getTs()->getDisplayWidth())-textBox.width)/2), top + height/2 - textBox.height/2);
	window->draw(m_text);
}

void Button::manageEvents(sf::Event &event, void *args)
{
	switch(event.type)
	{
		case sf::Event::MouseButtonPressed:
			if(contains(event.mouseButton.x, event.mouseButton.y))
				callback(args);
			break;
		default:
			break;
	}
}
