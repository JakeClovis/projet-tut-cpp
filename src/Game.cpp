#include "Game.h"

Game::Game(): m_tileSize(DEFAULT_TILE_SIZE)
{
	cout << "** Initializating the game controller: " << endl <<
			" * m_tileSize=" << DEFAULT_TILE_SIZE << " [default]" << endl;
	setupTextures();
}

Game::Game(int tileSize): m_tileSize(tileSize)
{
	cout << "** Initializating the game controller: " << endl <<
			" * m_tileSize=" << m_tileSize << endl;
	setupTextures();
}

void Game::setupTextures()
{
	if(!m_textureBase.loadFromFile("res/textures/player.png"))
	{
		cerr << "(X)FATAL:res/player.png: unable to load file" << endl;
		exit(TEXTURE_ERROR);
	}
	cout << " * Loaded texture " << &m_textureBase << endl;
}

void Game::start()
{
	m_window.create(m_tileSize*17, m_tileSize*13);

	//TMP CODE TESTING PURPOSES
	unsigned int tick = 1;
	Tileset ts(&m_textureBase, 2, 12, 17, 27, m_tileSize, m_tileSize*((float)27/(float)17));
	Tile *test = ts.createTile({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
	sf::Clock clockTest;
	sf::Time elapsedTime;
	//END OF TMP CODE

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
		
		//TMP CODE TESTING PURPOSES
			m_window.draw(*(test->getSprite(tick, 0, 0)));
			m_window.draw(*(test->getSprite(tick+3, m_tileSize, 0)));
			m_window.draw(*(test->getSprite(tick+6, 2*m_tileSize, 0)));
			m_window.draw(*(test->getSprite(tick+9, 3*m_tileSize, 0)));
			elapsedTime = clockTest.getElapsedTime();
			if(elapsedTime.asSeconds() >= 0.2)
			{
				clockTest.restart();
				tick = tick==1?2:1;
			}
		//END

		m_window.display();
	}

	//TMP CODE TESTING PURPOSES
	delete test;
	//END
}
