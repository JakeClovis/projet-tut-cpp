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
	if(!m_textureBase.loadFromFile("res/textures/test.png"))
	{
		cerr << "(X)FATAL:res/test.png: unable to load file" << endl;
		exit(TEXTURE_ERROR);
	}
	cout << " * Loaded texture " << &m_textureBase << endl;
}

void Game::start()
{
	m_window.create(m_tileSize*17, m_tileSize*13);

	//TMP CODE TESTING PURPOSES
	Tileset ts(&m_textureBase, 10, 5, 16, 16, m_tileSize, m_tileSize);
	Tile *test = ts.createTile(1, 1);
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
		m_window.draw(*(test->getSprite(0, 0)));
		m_window.draw(*(test->getSprite(1*m_tileSize, 0)));
		m_window.draw(*(test->getSprite(0, 1*m_tileSize)));
		//END

		m_window.display();
	}

	//TMP CODE TESTING PURPOSES
	delete test;
	//END
}
