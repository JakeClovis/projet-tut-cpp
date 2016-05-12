#include "Game.h"

Game::Game(GameWindow* window): Controller(window)
{
	ResourceAllocator::allocateTexture(m_textures, "player", "res/textures/player.png");
	ResourceAllocator::allocateTexture(m_textures, "level", "res/textures/level.png");
	
	ResourceAllocator::allocateTileset(m_tilesets, "level", new Tileset(m_textures["level"], 3, 6, 16, 16, m_window->getTileSize(), m_window->getTileSize()));
	ResourceAllocator::allocateTileset(m_tilesets, "player", new Tileset(m_textures["player"], 4, 3, 32, 32, m_window->getTileSize()*2, m_window->getTileSize()*2)); 

	ResourceAllocator::allocateTileSystem(m_tilesystems, "level",  m_tilesets["level"]);
	m_tilesystems["level"]->registerTile<MapTile>(1, {1, 2, 3}, {1, 1, 1}, TileType::RANDOMIZED, false, false);
	m_tilesystems["level"]->registerTile<MapTile>(2, {1, 2, 3, 4, 5, 6}, {2, 2, 2, 2, 2, 2}, TileType::DEFAULT, true, true);
	m_tilesystems["level"]->registerTile<MapTile>(3, {1, 2, 3, 4}, {3, 3, 3, 3}, TileType::RANDOMIZED, true, false);
	ResourceAllocator::allocateTileSystem(m_tilesystems, "player", m_tilesets["player"]);
	m_tilesystems["player"]->registerTile(Orientation::TOP, {1, 2, 3}, {1, 1, 1});
	m_tilesystems["player"]->registerTile(Orientation::RIGHT, {1, 2, 3}, {2, 2, 2});
	m_tilesystems["player"]->registerTile(Orientation::BOTTOM, {1, 2, 3}, {3, 3, 3});
	m_tilesystems["player"]->registerTile(Orientation::LEFT, {1, 2, 3}, {4, 4, 4});

	m_player1 = new LivingEntity(m_tilesystems["player"], {
					{Orientation::TOP, sf::IntRect(12, 21, 9, 8)},
					{Orientation::RIGHT, sf::IntRect(12, 21, 11, 8)},
					{Orientation::BOTTOM, sf::IntRect(12, 21, 9, 8)},
					{Orientation::LEFT, sf::IntRect(10, 21, 11, 8)}
					}, sf::Vector2f(16, 24), sf::Vector2f(1.5*m_window->getTileSize(), 1.5*m_window->getTileSize()), 1);
	m_player2 = new LivingEntity(m_tilesystems["player"], {
					{Orientation::TOP, sf::IntRect(12, 21, 9, 8)},
					{Orientation::RIGHT, sf::IntRect(12, 21, 11, 8)},
					{Orientation::BOTTOM, sf::IntRect(12, 21, 9, 8)},
					{Orientation::LEFT, sf::IntRect(10, 21, 11, 8)}
					}, sf::Vector2f(16, 24), sf::Vector2f(13.5*m_window->getTileSize(), 1.5*m_window->getTileSize()), 1);


	m_view.reset(sf::FloatRect(0, 0, m_window->getSize().x - 2*m_window->getTileSize(), m_window->getSize().y - 2*m_window->getTileSize()));
	m_view.setViewport(sf::FloatRect(
							1/(float)m_window->getWidth(), 
							1/(float)m_window->getHeight(), 
							(m_window->getWidth()-2)/(float)m_window->getWidth(), 
							(m_window->getHeight()-2)/(float)m_window->getHeight()));
}

Game::~Game()
{
	cout << "** Deleting the Game Controller " << this << endl;
	delete m_player1;
	delete m_player2;
}

void Game::manageEvents()
{
	sf::Event event;
	while(m_window->pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::KeyPressed:
				switch(event.key.code)
				{
					case sf::Keyboard::Escape:
						m_isPlaying = false;
						break;
					default:
						break;
				}
				break;
			default:
				break;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			m_player2->setSpeed(sf::Vector2f(0, -SPEED_FACTOR*m_window->getTileSize()));
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			m_player2->setSpeed(sf::Vector2f(0, SPEED_FACTOR*m_window->getTileSize()));
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			m_player2->setSpeed(sf::Vector2f(-SPEED_FACTOR*m_window->getTileSize(), 0));
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			m_player2->setSpeed(sf::Vector2f(SPEED_FACTOR*m_window->getTileSize(), 0));
		else
			m_player2->setSpeed(sf::Vector2f(0, 0));

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			m_player1->setSpeed(sf::Vector2f(0, -SPEED_FACTOR*m_window->getTileSize()));
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			m_player1->setSpeed(sf::Vector2f(0, SPEED_FACTOR*m_window->getTileSize()));
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			m_player1->setSpeed(sf::Vector2f(-SPEED_FACTOR*m_window->getTileSize(), 0));
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			m_player1->setSpeed(sf::Vector2f(SPEED_FACTOR*m_window->getTileSize(), 0));
		else
			m_player1->setSpeed(sf::Vector2f(0, 0));


		m_window->manageEvents(event);
	}
}

void Game::start()
{
	srand(time(NULL));
	m_isPlaying = true;

	//TMP CODE TESTING PURPOSES
	Tilemap testMap(m_tilesystems["level"], m_window->getWidth()-2, m_window->getHeight()-2);
	testMap.setMap({
					{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, },
					{3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, },
					{3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, },
					{3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, },
					{3, 1, 3, 1, 3, 1, 3, 2, 3, 1, 3, 1, 3, 1, 3, },
					{3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, },
					{3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, },
					{3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, },
					{3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, },
					{3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, },
					{3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, },
					});

	m_timer.restart();	
	//END OF TMP CODE

	while(m_isPlaying && m_window->isOpen())
	{
		sf::Time elapsedTime = m_timer.restart();
		manageEvents();

		m_player1->updateState(elapsedTime, &testMap);
		m_player2->updateState(elapsedTime, &testMap);
	
		m_window->clear(sf::Color(100, 100, 100));
		
		m_window->setView(m_view);

		//TMP CODE TESTING PURPOSES
		testMap.draw(m_window);
		m_player1->draw(m_window);
		m_player2->draw(m_window);

		m_window->setView(m_window->getDefaultView());
		//END
	
		m_window->setView(m_window->getDefaultView());

		m_window->display();
	}
}
