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
	m_tilesystems["button"]->registerTile(1, m_tilesystems["button"]->getTs()->createTile({1, 2, 3}, {1, 1, 1}));
	m_tilesystems["button"]->registerTile(2, m_tilesystems["button"]->getTs()->createTile({1, 2, 3}, {2, 2, 2}));

	ResourceAllocator::allocateFont(m_fonts, "default", "res/fonts/fipps.ttf");

	playButton = new Button(0, 530, m_tilesystems["button"], "Jouer", m_fonts["default"],
		[](void *arg) -> void {
				GameWindow *w = (GameWindow*)arg;
				Game *g = new Game(w);
				g->start();
				delete g;
		});
	playButton->left = m_window->getSize().x/2 - playButton->width/2; 
	quitButton = new Button(0, 550+m_tilesystems["button"]->getTs()->getDisplayHeight(), m_tilesystems["button"], "Quitter", m_fonts["default"],
		[](void *arg) -> void {
				GameWindow *w = (GameWindow*)arg;
				w->close();
		});
	quitButton->left = m_window->getSize().x/2 - quitButton->width/2; 

	background.setTexture(*m_textures["background"]);
	background.setScale(m_window->getSize().x/(float)m_textures["background"]->getSize().x,m_window->getSize().y/(float)m_textures["background"]->getSize().y);
	logo.setTexture(*m_textures["logo"]);
	logo.setScale(0.6f, 0.6f);
	logo.setPosition(m_window->getSize().x/2 - 0.6f*m_textures["logo"]->getSize().x/2, 200);

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
		switch(event.type)
		{
			case sf::Event::Closed:
				m_window->close();
				break;
			case sf::Event::Resized:
				m_toRectifyRatio = true;
				break;
			case sf::Event::MouseButtonPressed:
				if(playButton->contains(event.mouseButton.x, event.mouseButton.y))
				{
					m_musics["title"]->stop();
					playButton->callback((void*)m_window);
					m_musics["title"]->play();
				}
				else if(quitButton->contains(event.mouseButton.x, event.mouseButton.y))
					quitButton->callback((void*)m_window);
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
