#include "Game.h"

Game::Game(): m_tileSize(DEFAULT_TILE_SIZE)
{
	cout << "** Initializating the game controller: " << endl <<
			" * m_tileSize=" << DEFAULT_TILE_SIZE << " [default]" << endl;
}

Game::Game(int tileSize): m_tileSize(tileSize)
{
	cout << "** Initializating the game controller: " << endl <<
			" * m_tileSize=" << m_tileSize << endl;
}

void Game::start()
{
	m_window.create(m_tileSize*17, m_tileSize*13);

	while(m_window.isOpen())
	{
		sf::Event event;
		while(m_window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				m_window.close();
			}
		}

		m_window.clear(sf::Color::White);

		m_window.display();
	}
}
