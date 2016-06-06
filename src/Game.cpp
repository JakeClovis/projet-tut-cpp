#include "Game.h"

Game::Game(GameWindow* window): Controller(window)
{
	ResourceAllocator::allocateTexture(m_textures, "player", "res/textures/player.png"); //texture du joueur
	ResourceAllocator::allocateTexture(m_textures, "level", "res/textures/level.png"); //texture du niveau
	ResourceAllocator::allocateTexture(m_textures, "bomb", "res/textures/bomb.png"); //texture de la bombe
	ResourceAllocator::allocateTexture(m_textures, "background", "res/textures/background.png"); //texture d'arrière plan
	
	//On définit les paramètres des Tileset d'après les textures chargées en mémoire
	ResourceAllocator::allocateTileset(m_tilesets, "level", new Tileset(m_textures["level"], 10, 6, 16, 16, m_window->getTileSize(), m_window->getTileSize()));
	ResourceAllocator::allocateTileset(m_tilesets, "player", new Tileset(m_textures["player"], 4, 3, 32, 32, m_window->getTileSize()*2, m_window->getTileSize()*2));
	ResourceAllocator::allocateTileset(m_tilesets, "bomb", new Tileset(m_textures["bomb"], 8, 4, 16, 16, m_window->getTileSize(), m_window->getTileSize()));
	ResourceAllocator::allocateTileset(m_tilesets, "background", new Tileset(m_textures["background"], 6, 12, 16, 16, m_window->getTileSize(), m_window->getTileSize()));

	//On enregistre le TileSystem de la bombe, avec un tile pour la bombe, 1 pour le centre de l'explosion, 4 pour les extrêmités de branche d'explosion, et 2 pour les branches
	ResourceAllocator::allocateTileSystem(m_tilesystems, "bomb", m_tilesets["bomb"]);
	m_tilesystems["bomb"]->registerTile(1, {1, 2, 3, 4}, {1, 1, 1, 1});
	m_tilesystems["bomb"]->registerTile(2, {1, 2, 3, 4}, {2, 2, 2, 2});
	m_tilesystems["bomb"]->registerTile(3, {1, 2, 3, 4}, {3, 3, 3, 3});
	m_tilesystems["bomb"]->registerTile(4, {1, 2, 3, 4}, {4, 4, 4, 4});
	m_tilesystems["bomb"]->registerTile(5, {1, 2, 3, 4}, {5, 5, 5, 5});
	m_tilesystems["bomb"]->registerTile(6, {1, 2, 3, 4}, {6, 6, 6, 6});
	m_tilesystems["bomb"]->registerTile(7, {1, 2, 3, 4}, {7, 7, 7, 7});
	m_tilesystems["bomb"]->registerTile(8, {1, 2, 3, 4}, {8, 8, 8, 8});

	//On enregistre le TileSystem du niveau, avec toutes les tuiles correspondantes
	ResourceAllocator::allocateTileSystem(m_tilesystems, "level",  m_tilesets["level"]);
	m_tilesystems["level"]->registerTile<MapTile>(1, {1, 2, 3}, {1, 1, 1}, TileType::RANDOMIZED, false, false); //Herbe
	m_tilesystems["level"]->registerTile<MapTile>(2, {1, 2, 3, 4}, {3, 3, 3, 3}, TileType::RANDOMIZED, true, true); //pierres destructibles
	m_tilesystems["level"]->registerTile<MapTile>(3, {1, 2, 3, 4, 5, 6}, {2, 2, 2, 2, 2, 2}, TileType::TRANSITIONAL, true, true); //animation de destruction
	m_tilesystems["level"]->registerTile<MapTile>(4, 5, 3, TileType::DEFAULT, true, false); //pierres indestructibles
	m_tilesystems["level"]->registerTile<MapTile>(5, 1, 4, TileType::DEFAULT, true, false); //bordure herbeuse supérieure
	m_tilesystems["level"]->registerTile<MapTile>(6, 2, 4, TileType::DEFAULT, true, false); //bordure herbeuse supérieure coin gauche
	m_tilesystems["level"]->registerTile<MapTile>(7, 3, 4, TileType::DEFAULT, true, false); //bordure herbeuse supérieure coin droit
	m_tilesystems["level"]->registerTile<MapTile>(8, 4, 4, TileType::DEFAULT, true, false); //bordure herbeuse latérale gauche coin
	m_tilesystems["level"]->registerTile<MapTile>(10, 5, 4, TileType::DEFAULT, true, false); //bordure herbeuse latérale gauche
	m_tilesystems["level"]->registerTile<MapTile>(9, 6, 4, TileType::DEFAULT, true, false); //bordure herbeuse latérale droite coin
	m_tilesystems["level"]->registerTile<MapTile>(11, 6, 3, TileType::DEFAULT, true, false); //bordure herbeuse latérale droite
	m_tilesystems["level"]->registerTile<MapTile>(12, 1, 5, TileType::DEFAULT, true, false); //pont gauche haut
	m_tilesystems["level"]->registerTile<MapTile>(13, 2, 5, TileType::DEFAULT, true, false); //pont centre haut
	m_tilesystems["level"]->registerTile<MapTile>(14, 3, 5, TileType::DEFAULT, true, false); //pont droite haut
	m_tilesystems["level"]->registerTile<MapTile>(15, 1, 6, TileType::DEFAULT, false, false); //pont gauche milieu
	m_tilesystems["level"]->registerTile<MapTile>(16, 2, 6, TileType::DEFAULT, false, false); //pont centre milieu
	m_tilesystems["level"]->registerTile<MapTile>(17, 3, 6, TileType::DEFAULT, false, false); //pont droite milieu
	m_tilesystems["level"]->registerTile<MapTile>(18, 4, 5, TileType::DEFAULT, true, false); //pont gauche bas
	m_tilesystems["level"]->registerTile<MapTile>(19, 5, 5, TileType::DEFAULT, true, false); //pont centre bas
	m_tilesystems["level"]->registerTile<MapTile>(20, 6, 5, TileType::DEFAULT, true, false); //pont droite bas
	m_tilesystems["level"]->registerTile<MapTile>(21, 4, 6, TileType::DEFAULT, true, false); //bord supérieur gauche
	m_tilesystems["level"]->registerTile<MapTile>(22, 5, 6, TileType::DEFAULT, true, false); //bord supérieur centre
	m_tilesystems["level"]->registerTile<MapTile>(23, 6, 6, TileType::DEFAULT, true, false); //bord supérieur droite
	m_tilesystems["level"]->registerTile<MapTile>(24, 1, 7, TileType::DEFAULT, true, false); //bord milieu gauche A
	m_tilesystems["level"]->registerTile<MapTile>(25, 1, 8, TileType::DEFAULT, true, false); //bord milieu gauche B
	m_tilesystems["level"]->registerTile<MapTile>(26, 2, 7, TileType::DEFAULT, true, false); //bord milieu droite A
	m_tilesystems["level"]->registerTile<MapTile>(27, 2, 8, TileType::DEFAULT, true, false); //bord milieu droite B
	m_tilesystems["level"]->registerTile<MapTile>(28, 4, 7, TileType::DEFAULT, true, false); //bord inférieur gauche
	m_tilesystems["level"]->registerTile<MapTile>(29, 5, 7, TileType::DEFAULT, true, false); //bord inférieur centre
	m_tilesystems["level"]->registerTile<MapTile>(30, 6, 7, TileType::DEFAULT, true, false); //bord inférieur droite
	m_tilesystems["level"]->registerTile<MapTile>(31, 3, 7, TileType::DEFAULT, false, false); //escalier haut bas
	m_tilesystems["level"]->registerTile<MapTile>(32, 4, 7, TileType::DEFAULT, false, false); //escalier gauche droite
	m_tilesystems["level"]->registerTile<MapTile>(33, 2, 9, TileType::DEFAULT, true, false); //limite milieu gauche A
	m_tilesystems["level"]->registerTile<MapTile>(34, 2, 10, TileType::DEFAULT, true, false); //limite milieu gauche B
	m_tilesystems["level"]->registerTile<MapTile>(35, 3, 9, TileType::DEFAULT, true, false); //limite milieu droite A
	m_tilesystems["level"]->registerTile<MapTile>(36, 3, 10, TileType::DEFAULT, true, false); //limite milieu droite B
	m_tilesystems["level"]->registerTile<MapTile>(37, 1, 9, TileType::DEFAULT, true, false); //mur milieu gauche A
	m_tilesystems["level"]->registerTile<MapTile>(38, 1, 10, TileType::DEFAULT, true, false); //mur milieu gauche B
	m_tilesystems["level"]->registerTile<MapTile>(39, 4, 9, TileType::DEFAULT, true, false); //mur milieu droite A
	m_tilesystems["level"]->registerTile<MapTile>(40, 4, 10, TileType::DEFAULT, true, false); //mur milieu droite B
	m_tilesystems["level"]->registerTile<MapTile>(41, 5, 10, TileType::DEFAULT, true, false); //limite supérieur gauche 1
	m_tilesystems["level"]->registerTile<MapTile>(42, 6, 10, TileType::DEFAULT, true, false); //limite supérieur gauche 2
	m_tilesystems["level"]->registerTile<MapTile>(43, 6, 9, TileType::DEFAULT, true, false); //limite supérieur droite 1
	m_tilesystems["level"]->registerTile<MapTile>(44, 5, 9, TileType::DEFAULT, true, false); //limite supérieur droite 2
	m_tilesystems["level"]->registerTile<MapTile>(45, 4, 8, TileType::DEFAULT, true, false); //limite inférieur gauche
	m_tilesystems["level"]->registerTile<MapTile>(46, 5, 8, TileType::DEFAULT, true, false); //limite inférieur centre
	m_tilesystems["level"]->registerTile<MapTile>(47, 6, 8, TileType::DEFAULT, true, false); //limite inférieur droite

	//Le TileSystem de l'arrière plan, juste un ensemble de tuiles de décoration
	ResourceAllocator::allocateTileSystem(m_tilesystems, "background", m_tilesets["background"]);
	//On va allouer l'intégralité des Tuiles. Il y aura plusieurs tuiles vides, mais ce n'est pas grave.
	for(int i = 1 ; i <= m_tilesystems["background"]->getTs()->getRows() ; i++)
		for(int j = 1 ; j <= m_tilesystems["background"]->getTs()->getCols() ; j++)
			m_tilesystems["background"]->registerTile((i-1)*m_tilesystems["background"]->getTs()->getCols()+j, j, i);

	//Le TileSystem du joueur comporte un Tile par orientation	
	ResourceAllocator::allocateTileSystem(m_tilesystems, "player", m_tilesets["player"]);
	m_tilesystems["player"]->registerTile(Orientation::TOP, {1, 2, 3}, {1, 1, 1}); //haut
	m_tilesystems["player"]->registerTile(Orientation::RIGHT, {1, 2, 3}, {2, 2, 2}); //droite
	m_tilesystems["player"]->registerTile(Orientation::BOTTOM, {1, 2, 3}, {3, 3, 3}); //bas
	m_tilesystems["player"]->registerTile(Orientation::LEFT, {1, 2, 3}, {4, 4, 4}); //gauche
	
	//On crée 2 joueurs avec leurs touches
	m_player1 = new Player(m_tilesystems["player"], {
					{Orientation::TOP, sf::IntRect(12, 21, 9, 8)},
					{Orientation::RIGHT, sf::IntRect(12, 21, 11, 8)},
					{Orientation::BOTTOM, sf::IntRect(12, 21, 9, 8)},
					{Orientation::LEFT, sf::IntRect(10, 21, 11, 8)}
					}, sf::Vector2f(16, 24), sf::Vector2f(2.5*m_window->getTileSize(), 1.5*m_window->getTileSize()), 1, {
					sf::Keyboard::Z,
					sf::Keyboard::D,
					sf::Keyboard::S,
					sf::Keyboard::Q,
					sf::Keyboard::A}, m_tilesystems["bomb"]);
	m_player2 = new Player(m_tilesystems["player"], {
					{Orientation::TOP, sf::IntRect(12, 21, 9, 8)},
					{Orientation::RIGHT, sf::IntRect(12, 21, 11, 8)},
					{Orientation::BOTTOM, sf::IntRect(12, 21, 9, 8)},
					{Orientation::LEFT, sf::IntRect(10, 21, 11, 8)}
					}, sf::Vector2f(16, 24), sf::Vector2f(14.5*m_window->getTileSize(), 1.5*m_window->getTileSize()), 1, {
					sf::Keyboard::Up,
					sf::Keyboard::Right,
					sf::Keyboard::Down,
					sf::Keyboard::Left,
					sf::Keyboard::RControl}, m_tilesystems["bomb"]);
	
	//On crée la carte 
	m_physicalMap = new Tilemap(m_tilesystems["level"], m_window->getWidth(), m_window->getHeight()-1);
	m_physicalMap->setMap({
					{41, 42, 5, 5, 5, 5, 5, 6, 0, 7, 5, 5, 5, 5, 5, 44, 43},
					{37, 33, 1, 1, 2, 1, 1, 10, 0, 11, 2, 2, 1, 1, 1, 35, 39},
					{38, 34, 1, 4, 2, 4, 2, 12, 13, 14, 2, 4, 2, 4, 1, 36, 40},
					{37, 33, 2, 1, 1, 2, 1, 15, 16, 17, 1, 2, 1, 2, 2, 35, 39},
					{38, 34, 1, 4, 1, 4, 1, 18, 19, 20, 1, 4, 2, 4, 2, 36, 40},
					{37, 33, 1, 1, 1, 2, 1, 8, 5, 9, 1, 2, 2, 1, 2, 35, 39},
					{38, 34, 2, 4, 1, 21, 22, 22, 22, 22, 22, 23, 1, 4, 2, 36, 40},
					{37, 33, 1, 2, 1, 24, 1, 1, 1, 1, 2, 26, 2, 1, 2, 35, 39},
					{38, 34, 4, 4, 1, 25, 2, 4, 1, 4, 2, 27, 1, 4, 1, 36, 40},
					{37, 33, 1, 4, 2, 24, 2, 1, 1, 1, 2, 26, 1, 1, 2, 35, 39},
					{38, 34, 1, 4, 2, 28, 29, 29, 31, 29, 29, 30, 1, 4, 1, 36, 40},
					{37, 33, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 1, 35, 39},
					{38, 45, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 47, 40},
					});

	//Arrière plan
	m_backgroundMap = new Tilemap(m_tilesystems["background"], m_window->getWidth(), m_window->getHeight()-1);
	m_backgroundMap->setMap({
					{4, 4, 5, 6, 7, 8, 9, 10, 11, 12, 5, 4, 4, 4, 4, 4, 4},
					{17, 17, 17, 18, 19, 20, 21, 22, 23, 24, 18, 17, 17, 17, 17, 17, 17},
					{28, 28, 29, 30, 31, 32, 33, 34, 35, 36, 28, 28, 28, 28, 28, 28, 28},
					{1, 1, 1, 1, 1, 1, 1, 49, 50, 51, 1, 1, 1, 1, 1, 1, 1},
					{1, 1, 1, 1, 1, 1, 1, 61, 62, 63, 1, 1, 1, 1, 1, 1, 1},
					{1, 1, 1, 1, 1, 1, 1, 50, 51, 52, 1, 1, 1, 1, 1, 1, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
					});

	//On définit la vue de jeu
	m_view.reset(sf::FloatRect(0, 0, m_window->getSize().x, m_window->getSize().y - 1*m_window->getTileSize()));
	m_view.setViewport(sf::FloatRect(
							0, 
							1/(float)m_window->getHeight(), 
							(m_window->getWidth())/(float)m_window->getWidth(), 
							(m_window->getHeight()-1)/(float)m_window->getHeight()));
}

Game::~Game()
{
	cout << "** Deleting the Game Controller " << this << endl;
	delete m_player1;
	delete m_player2;
	delete m_physicalMap;
	for(unsigned int i = 0 ; i < m_entities.size() ; i++)
		delete m_entities[i];
}

void Game::manageEvents()
{
	sf::Event event;
	while(m_window->pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::KeyPressed: //Si on a cliqué sur echap, on met le jeu en pause
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
	
		//On gère les évènements des deux joueurs	
		vector<void*> v = {(void*)m_window, (void*)m_physicalMap, (void*)&m_entities};
		m_player1->manageEvents(event, (void*)&v);
		m_player2->manageEvents(event, (void*)&v);
		
		//On gère les évènements spécifiques de la fenêtre
		m_window->manageEvents(event);
	}
}

void Game::start()
{
	//on démarre le jeu
	srand(time(NULL));
	m_isPlaying = true;
	m_timer.restart();	

	while(m_isPlaying && m_window->isOpen()) //tant que la fenêtre reste ouverte et qu'on a pas quitté le jeu via le menu pause, on continue à jouer
	{
		sf::Time elapsedTime = m_timer.restart(); //on récupère le temps écoulé
		manageEvents(); //gestion des évènements utilisateur
	
		//On met à jour l'état de la carte et de toutes les entités sur la carte
		m_physicalMap->updateState(elapsedTime);	
		m_player1->updateState(this, elapsedTime, m_physicalMap);
		m_player2->updateState(this, elapsedTime, m_physicalMap);
		for(unsigned int i = 0 ; i < m_entities.size() ; i++)
			m_entities[i]->updateState(this, elapsedTime, m_physicalMap);
	
		//On efface l'affichage
		m_window->clear(sf::Color(100, 100, 100));
		
		//On se place dans la vue de jeu
		m_window->setView(m_view);

		//On affiche la carte
		m_backgroundMap->draw(m_window);
		m_physicalMap->draw(m_window);
		
		//Puis on dessine les entités
		for(unsigned int i = 0 ; i < m_entities.size() ; i++)
			m_entities[i]->draw(m_window);

		//...Ainsi que les deux joueurs
		m_player1->draw(m_window);
		m_player2->draw(m_window);
	
		//On se repositionne dans la vue principale	
		m_window->setView(m_window->getDefaultView());

		//On raffraichit l'affichage
		m_window->display();
	}
}

void Game::notifyUpdate()
{
	unsigned int i = 0;
	bool notFound = true;
	
	//notifyUpdate() ne traite qu'une notification par appel
	while(i<m_entities.size() && notFound)
	{
		//Si l'entité est une bombe et qu'elle fini d'exploser
		if(m_entities[i]->getHealth()==-1)
		{
			if(Bomb* b = dynamic_cast<Bomb*>(m_entities[i]))
			{
				b->getPlayer()->notifyExplosion(); //on notifie le joueur de l'explosion
				delete m_entities[i]; //on supprime la bombe
				notFound = false;
				m_entities.erase(m_entities.begin()+i); //on supprime l'entrée dans le vector
			}
		}
		else
			i++;
	}
}

vector<Entity*> *Game::getEntities()
{
	return &m_entities;
}

Player *Game::getPlayer(int i)
{
	if(i == 1)
		return m_player1;
	else
		return m_player2;
}
