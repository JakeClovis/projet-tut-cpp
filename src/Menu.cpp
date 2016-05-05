#include "Menu.h"

Menu::Menu(GameWindow *window): Controller(window)
{
}

Menu::~Menu()
{
	cout << "** Deleting the Controller " << this << endl;
}

void Menu::manageEvents()
{
	sf::Event event;
	while(m_window->pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				m_window->close();
				break;
			case sf::Event::Resized:
				m_toRectifyRatio = true;
				break;
			default:
				break;
		}
	}

	if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_toRectifyRatio)
	{
		m_window->rectifyRatio();
		m_toRectifyRatio = false;
	}
}

void Menu::start()
{
	m_toRectifyRatio = false;
	Game *g = new Game(m_window);
	g->start();
	delete g;

	while(m_window->isOpen())
		manageEvents();	
}
