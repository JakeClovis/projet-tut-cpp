#include "Game.h"

Game::Game(GameWindow *window): m_window(window)
{
	cout << "** Initializating the game controller" << endl;
	setupResources();
}

Game::~Game()
{
	cout << "** Ending the game controller" << endl;
	
	cout << " * Deallocating the texture " << m_textures["player"] << endl;
	delete m_textures["player"];
	cout << " * Deallocating the texture " << m_textures["level"] << endl;
	delete m_textures["level"];
	
	cout << " * Deallocating the Tileset " << m_tilesets["level"] << endl;
	delete m_tilesets["level"];
}

void Game::setupResources()
{
	ResourceAllocator::allocateTexture(m_textures, "player", "res/textures/player.png");
	ResourceAllocator::allocateTexture(m_textures, "level", "res/textures/level.png");
	
	ResourceAllocator::allocateTileset(m_tilesets, "level", new Tileset(m_textures["level"], 3, 6, 16, 16, m_window->getTileSize(), m_window->getTileSize()));
}

void Game::manageEvents()
{
	sf::Event event;
	while(m_window->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			m_window->close();
		}
	}
}

void Game::start()
{
	srand(time(NULL));

	//TMP CODE TESTING PURPOSES
	TileSystem ts(m_tilesets["level"]);
	ts.registerTile(1, ts.getTs()->createTile({1, 2, 3}, {1, 1, 1}));
	ts.registerTile(2, ts.getTs()->createTile({1, 2, 3, 4, 5, 6}, {2, 2, 2, 2, 2, 2}));
	ts.registerTile(3, ts.getTs()->createTile({1, 2, 3}, {3, 3, 3}));
	Tilemap testMap(&ts, 9, 5);
	testMap.setMap({
					{3, 3, 3, 3, 3, 3, 3, 3, 3},
					{3, 1, 1, 1, 3, 1, 1, 1, 3},
					{3, 3, 1, 1, 2, 2, 2, 1, 3},
					{3, 1, 1, 1, 1, 1, 3, 1, 3},
					{3, 3, 3, 3, 3, 3, 3, 3, 3}
					});
	//END OF TMP CODE

	while(m_window->isOpen())
	{
		manageEvents();
	
		m_window->clear(sf::Color::White);
		
		//TMP CODE TESTING PURPOSES
		for(int i = 0 ; i < testMap.getWidth() ; i++)
			for(int j = 0 ; j < testMap.getHeight() ; j++)
			{
				sf::Sprite *toDraw = testMap.readPos(i, j);
				if(toDraw != NULL) 
					m_window->draw(*toDraw);
			}
		//END

		m_window->display();
	}
}
