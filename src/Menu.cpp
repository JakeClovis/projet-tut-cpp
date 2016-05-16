#include "Menu.h"

Menu::Menu(GameWindow *window): Controller(window)
{
	ResourceAllocator::allocateTexture(m_textures, "button", "res/textures/button.png");
	ResourceAllocator::allocateTexture(m_textures, "background", "res/textures/title.png");
	ResourceAllocator::allocateTexture(m_textures, "logo", "res/textures/logo.png");
	m_textures["background"]->setSmooth(true);
	m_textures["logo"]->setSmooth(true);

	ResourceAllocator::allocateTileset(m_tilesets, "button", new Tileset(m_textures["button"], 2, 3, 32, 32, m_window->getTileSize(), m_window->getTileSize()));

	ResourceAllocator::allocateTileSystem(m_tilesystems, "button",  m_tilesets["button"]);
	m_tilesystems["button"]->registerTile(1, {1, 2, 3}, {1, 1, 1});
	m_tilesystems["button"]->registerTile(2, {1, 2, 3}, {2, 2, 2});

	ResourceAllocator::allocateFont(m_fonts, "default", "res/fonts/e4_2017.ttf");

	playButton = new Button(m_tilesystems["button"], 0, 2*m_window->getSize().y/3, "Nouvelle partie", m_fonts["default"],
		[](void *arg) -> void {
				vector<void*>* v = (vector<void*>*) arg;
				Game *g = new Game((GameWindow*) (*v)[1]);
				((sf::Music*)(*v)[0])->stop();
				g->start();
				delete g;
				((sf::Music*)(*v)[0])->play();
		});
	playButton->left = m_window->getSize().x/2 - playButton->width/2; 
	quitButton = new Button(m_tilesystems["button"], 0, +2*m_window->getSize().y/3+3*m_tilesystems["button"]->getTs()->getDisplayHeight()/2, "Quitter", m_fonts["default"],
		[](void *arg) -> void {
				((GameWindow*)arg)->close();
		});
	quitButton->left = m_window->getSize().x/2 - quitButton->width/2; 

	background.setTexture(*m_textures["background"]);
	background.setScale(m_window->getSize().x/(float)m_textures["background"]->getSize().x,m_window->getSize().y/(float)m_textures["background"]->getSize().y);
	logo.setTexture(*m_textures["logo"]);
	float logoScale = 0.45f*(m_window->getTileSize()/(float)DEFAULT_TILE_SIZE);
	logo.setScale(logoScale, logoScale);
	logo.setPosition(m_window->getSize().x/2 - logoScale*m_textures["logo"]->getSize().x/2, m_window->getSize().y/3);

	ResourceAllocator::allocateMusic(m_musics, "title", "res/musics/title.ogg", true);
}

Menu::~Menu()
{
	cout << "** Deleting the Menu Controller " << this << endl;
	delete playButton;
	delete quitButton;
}

void Menu::manageEvents()
{
	sf::Event event;
	while(m_window->pollEvent(event))
	{
		m_window->manageEvents(event);

		vector<void*> v = {(void*)m_musics["title"], (void*)m_window};
		playButton->manageEvents(event, (void*)(&v));
		quitButton->manageEvents(event, (void*)m_window);
	}
}

void Menu::start()
{
	m_musics["title"]->play();
	

	while(m_window->isOpen())
	{
		manageEvents();	
		m_window->clear();

		m_window->draw(background);
		m_window->draw(logo);
		playButton->draw(m_window);
		quitButton->draw(m_window);

		m_window->display();
	}
}

void Menu::notifyUpdate()
{
}
