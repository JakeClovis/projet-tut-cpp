int main(int argc, char *argv[])
{
// Declaration des variables

	nStream nullStream;
	Menu *mainController = NULL;
	GameWindow window;
	streambuf *coutBackup = cout.rdbuf(&nullStream);
	int options, tileSize = 0;

	srand(time(NULL));

// Cas du mode de deboguage

	if(DEBUG_MODE)
		cout.rdbuf(coutBackup);

// Traitement des entrees de la ligne de commande

	while((options = getopt(argc, argv, "hvs:")) != -1)
		switch(options)
		{
		case 'h':
			cout.rdbuf(coutBackup);
			displayHelp(argv[0]);
			exit(0);
		case 'v':
			cout.rdbuf(coutBackup);
			break;
		case 's':
				tileSize = atoi(optarg);
				if(tileSize <= 0)
				{
					cerr << "atoi(\"" << optarg << "\"): incorrect value" << endl;
					cerr << "Try " << argv[0] << " -h for help." << endl;
					exit(GENERIC_ERROR);
				}
			break;
		default:
			cout.rdbuf(coutBackup);
			cerr << "Try " << argv[0] << " -h for help." << endl;
			exit(GENERIC_ERROR);
		}

// Instanciation du controleur principal

	cout << "Launching Bomberman clone v" << G_VERSION << "..." << endl <<
		   "Crafted by " << G_AUTHORS << endl;


	if(tileSize > 0)
		window.create(tileSize, 17, 14);
	else
		window.create(17, 14);

	mainController = new Menu(&window);
	mainController->start();

// Fermeture du programme

	delete mainController;

	cout.rdbuf(coutBackup);
	return 0;
}

// Extrait de Button.h
void (*m_callback)(void*);

// Extrait de Menu.cpp
quitButton = new Button([...],
		[](void *arg) -> void {
				((GameWindow*)arg)->close(); //quand on clique sur le bouton quitter on ferme la fenetre
		});

// Extrait de Player.cpp, implementation de void Player::manageEvents(sf::Event &event, void *args)
void Player::manageEvents(sf::Event &event, void *args)
{
	vector<void*> *a = (vector<void*>*) args;

	GameWindow *w = (GameWindow*)((*a)[0]);
	Tilemap *tm = (Tilemap*)((*a)[1]);
	vector<Entity*> *l = (vector<Entity*>*)((*a)[2]);
	// [...]
}

// Extrait de Game.cpp, appel a void Player::manageEvents(sf::Event&, void*)
// [...]
vector<void*> v = {(void*)m_window, (void*)m_physicalMap, (void*)&m_entities};
m_player1->manageEvents(event, (void*)&v);
// [...]

// Extrait de Game.cpp, dans void Game::notifyUpdate()
// [...]
//Si l'entite est une bombe et qu'elle a fini d'exploser
if(m_entities[i]->getHealth()==-1)
{
	if(Bomb* b = dynamic_cast<Bomb*>(m_entities[i]))
	{
		b->getPlayer()->notifyExplosion(); //on notifie le joueur de l'explosion
		delete m_entities[i]; //on supprime la bombe
		notFound = false;
		m_entities.erase(m_entities.begin()+i); //on supprime l'entree dans le vector
	}
}
// [...]

// Extrait de TileSystem.h
template<typename T = Tile>
void registerTile(unsigned int index, int i, int j, TileType ty=TileType::DEFAULT, bool c=NULL, bool b=NULL)
{
	// L'implementation est bien faite dans le header.
}

// Extrait de TileSystem.cpp
template<>
void TileSystem::registerTile<MapTile>(unsigned int index, int i, int j, TileType ty, bool c, bool b)
{
	// Comme c'est une specialisation, on place le code dans le .cpp.
}