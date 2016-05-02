#include "Game.h"

Game::Game(): m_tileSize(DEFAULT_TILE_SIZE)
{
	cout << "** Initializating the game controller: " << endl <<
			" * m_tileSize=" << DEFAULT_TILE_SIZE << " [default]" << endl;
	setupResources();
}

Game::Game(int tileSize): m_tileSize(tileSize)
{
	cout << "** Initializating the game controller: " << endl <<
			" * m_tileSize=" << m_tileSize << endl;
	setupResources();
}

void Game::setupResources()
{
	if(!m_texturePlayer.loadFromFile("res/textures/player.png")) //player texture
	{
		cerr << "(X)FATAL:res/player.png: unable to load file" << endl;
		exit(TEXTURE_ERROR);
	}
	cout << " * Loaded texture " << &m_texturePlayer << endl;

	if(!m_textureLevel.loadFromFile("res/textures/level.png")) //level texture
	{
		cerr << "(X)FATAL:res/level.png: unable to load file" << endl;
		exit(TEXTURE_ERROR);
	}
	cout << " * Loaded texture " << &m_textureLevel << endl;

	m_window.create(m_tileSize*17, m_tileSize*13); // Finally, we open the window
}

void Game::manageEvents()
{
	sf::Event event;
	while(m_window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			m_window.close();
		}
	}
}

void Game::start()
{
	srand(time(NULL));

	//TMP CODE TESTING PURPOSES
	//unsigned int tick = 1;
	TileSystem ts(new Tileset(&m_textureLevel, 3, 6, 16, 16, m_tileSize, m_tileSize));
	ts.registerTile(1, ts.getTs()->createTile({1, 2, 3}, {1, 1, 1}));
	ts.registerTile(2, ts.getTs()->createTile({1, 2, 3, 4, 5, 6}, {2, 2, 2, 2, 2, 2}));
	ts.registerTile(3, ts.getTs()->createTile({1, 2, 3}, {3, 3, 3}));
	Tilemap testMap(&ts, 9, 5);
	testMap.setMap({
					{3, 3, 3, 3, 3, 3, 3, 3, 3},
					{3, 1, 1, 1, 3, 1, 1, 1, 3},
					{3, 1, 1, 1, 2, 2, 2, 1, 3},
					{3, 1, 1, 1, 1, 1, 3, 1, 3},
					{3, 3, 3, 3, 3, 3, 3, 3, 3}
					});
	//END OF TMP CODE

	while(m_window.isOpen())
	{
		manageEvents();
	
		m_window.clear(sf::Color::White);
		
		//TMP CODE TESTING PURPOSES
		for(int i = 0 ; i < testMap.getWidth() ; i++)
			for(int j = 0 ; j < testMap.getHeight() ; j++)
			{
				sf::Sprite *toDraw = testMap.readPos(i, j);
				if(toDraw != NULL) 
					m_window.draw(*toDraw);
			}
		//END

		m_window.display();
	}
}
