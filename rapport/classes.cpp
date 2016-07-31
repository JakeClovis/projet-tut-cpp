class Bomb: public Entity
{
private:

	sf::Time m_duration;
	Player *m_player;
	unsigned int m_blastRadius;
	unsigned int m_maxSize[4];

public:

	Bomb(TileSystem *tilesys, sf::Vector2f center, sf::Vector2f position, int health, Player *player, sf::Time duration, unsigned int blastRadius);
	void updateState(Controller *controller, sf::Time &elapsed, Tilemap *world);
	void draw(GameWindow *window);
	Player *getPlayer();
};

class Button: public sf::IntRect, public IDrawable, public IHandlable
{
protected:

	sf::Text m_text;
	void (*m_callback)(void*);

public:

	Button(TileSystem *tilesys, int x, int y, string text, sf::Font *font, void(*callback)(void*));
	virtual ~Button();
	void callback(void* args);
	void draw(GameWindow*);
	void manageEvents(sf::Event &event, void *args=NULL);
	
};

class Controller
{
protected:

	GameWindow *m_window;
	map<string, sf::Texture*> m_textures;
	map<string, sf::Font*> m_fonts;
	map<string, Tileset*> m_tilesets;
	map<string, TileSystem*> m_tilesystems;
	map<string, sf::Music*> m_musics;
	virtual void manageEvents() = 0;

public:

	Controller(GameWindow *window);
	virtual ~Controller();
	virtual void start() = 0;
	virtual void notifyUpdate() = 0;
};

class Game: public Controller
{
private:
	
	sf::View m_view;
	sf::Clock m_timer;
	bool m_isPlaying;
	Player *m_player1,
	       *m_player2;
	int hasWon;
	Tilemap *m_physicalMap;
	Tilemap *m_backgroundMap;
	vector<Entity*> m_entities;
	void manageEvents();

public:

	Game(GameWindow *window);
	virtual ~Game();
	void start();
	void notifyUpdate();
	vector<Entity*> *getEntities();
	Player *getPlayer(int i);
};

class GameWindow : public sf::RenderWindow, public IHandlable
{
private:

	int m_tileSize;
	int m_width,
            m_height;
	bool m_toRectifyRatio;

public:

	void create(int width, int height);
	void create(int tileSize, int width, int height);
	int getTileSize();
	int getWidth();
	int getHeight();
	void rectifyRatio();
	void manageEvents(sf::Event &event, void *args=NULL);
};

class IDrawable
{
protected:

	TileSystem *m_tilesys;

public:

	IDrawable(TileSystem *tilesys);
	virtual void draw(GameWindow* window) = 0;
};

class Entity: public IDrawable
{
protected:

	sf::Clock m_watcher;
	sf::Clock m_timeAlive;
	int m_tick;
	int m_health;
	int m_maxHealth;
	sf::Vector2f m_position;
	sf::Vector2f m_center;
	map<Orientation, sf::IntRect> m_bBoxes;

public:

	Entity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health);
	virtual ~Entity();
	virtual void updateState(Controller *controller, sf::Time &elapsed, Tilemap *world) = 0;
	int getHealth();
	sf::Vector2f getPosition();
};

class IHandlable
{
public:

	virtual void manageEvents(sf::Event &event, void *args=NULL) = 0;
};

class LivingEntity: public Entity
{
protected:
	
	sf::Vector2f m_speed;
	Orientation m_orientation;
	void move(sf::Vector2f potential, Tilemap *world);

public:

	LivingEntity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health);
	void setSpeed(sf::Vector2f speed);
	void updateState(Controller *controller, sf::Time &elapsed, Tilemap *world);
	void draw(GameWindow* window);
};

class MapTile: public Tile
{
protected:
	
	bool m_collidable;
	bool m_breakable;

public:

	MapTile(sf::Sprite &s, TileType type=TileType::DEFAULT);
	MapTile(TileType type=TileType::DEFAULT);
	void setCollidable(bool c);
	void setBreakable(bool b);
	bool isCollidable();
	bool isBreakable();
};

class Menu: public Controller
{
private:

	void manageEvents();
	Button *playButton;
	Button *quitButton;
	sf::Sprite background;
	sf::Sprite logo;
	
public:

	Menu(GameWindow* window);
	virtual ~Menu();
	void start();
	void notifyUpdate();
};

class Player: public LivingEntity, public IHandlable
{
protected:

	unsigned int m_blastPower;
	unsigned int m_bombCount;
	unsigned int m_bombInventory;
	bool m_bombHasBeenDropped;
	TileSystem *m_bombTilesys;
	vector<sf::Keyboard::Key> m_controls; 
	void dropBomb(sf::Vector2f pos, vector<Entity*> *list);

public:

	Player(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health, vector<sf::Keyboard::Key> controls, TileSystem *bombTilesys);
	void manageEvents(sf::Event &event, void *args=NULL);
	void notifyExplosion();
	void hit();
	bool isOnCoord(unsigned int i, unsigned int j, Tilemap *world);

};

class ResourceAllocator
{
public:

	static void allocateTexture(map<string, sf::Texture*> &m, const string index, const string path);
	static void allocateMusic(map<string, sf::Music*> &m, const string index, const string path, bool isLoop=false);
	static void allocateFont(map<string, sf::Font*> &m, const string index, const string path);
	static void allocateTileset(map<string, Tileset*> &m, const string index, Tileset *t);
	static void allocateTileSystem(map<string, TileSystem*> &m, const string index, Tileset *t);
};

class Tile
{
protected:	
	
	vector<sf::Sprite*> m_sprites;
	TileType m_type;


public:

	Tile(sf::Sprite &s, TileType type=TileType::DEFAULT);
	Tile(TileType type=TileType::DEFAULT);
	virtual ~Tile();
	void addSprite(sf::Sprite &s);
	sf::Sprite *getSprite(float x, float y); 
	sf::Sprite *getSprite(unsigned int index, float x, float y);
	TileType getType();
	int getSpriteCount();
};

class Tilemap: public IDrawable
{
private:

	sf::Clock m_watcher;
	vector<vector<unsigned int>> m_map;
	vector<vector<int>> m_metadata;
	int m_width;
	int m_height;

public:

	Tilemap(TileSystem *tilesys, int width, int height);
	virtual ~Tilemap();
	void setMap(const vector<vector<unsigned int>> &map);
	int getWidth();
	int getHeight();
	sf::Vector2i toTileCoord(sf::Vector2f c);
	sf::Sprite *getSprite(int i, int j);
	sf::Sprite *getSprite(unsigned int index, int i, int j);
	Tile *getTile(unsigned int i, unsigned int j);
	void setTileIndex(unsigned int index, unsigned int i, unsigned int j, int metadata=-1);
	void attemptDestruction(unsigned int i, unsigned int j);
	int getMetadata(unsigned int i, unsigned int j);
	TileSystem *getTileSystem();
	virtual void updateState(sf::Time &elapsed);
	void draw(GameWindow*);
};

class Tileset
{
private:

	const sf::Texture *m_texture;
	int m_rows;
	int m_cols;
	int m_width; 
	int m_height;
	int m_displayWidth; 
	int m_displayHeight;

public:
	Tileset(const sf::Texture *tex, int rows, int cols, int width, int height, int displayWidth, int displayHeight);

	template<typename T = Tile>
	T *createTile(int i, int j, TileType ty=TileType::DEFAULT, bool c=false, bool b=false)
	{
		//[...]
	}
	
	template<typename T = Tile>
	T *createTile(vector<int> i,vector <int> j, TileType ty=TileType::DEFAULT, bool c=false, bool b=false)
	{
		//[...]
	}

	const sf::Texture *getTexture();
	int getDisplayWidth();
	int getDisplayHeight();
	int getWidth();
	int getHeight();
	int getRows();
	int getCols();
};

class TileSystem
{
private:

	Tileset *m_ts;
	map<unsigned int, Tile*> m_tilesList;

public:

	TileSystem(Tileset *ts);
	virtual ~TileSystem();

	template<typename T = Tile>
	void registerTile(unsigned int index, int i, int j, TileType ty=TileType::DEFAULT, bool c=NULL, bool b=NULL)
	{
		//[...]
	}

	template<typename T = Tile>
	void registerTile(unsigned int index, vector<int> i, vector<int> j, TileType ty=TileType::DEFAULT, bool c=NULL, bool b=NULL)
	{
		//[...]
	}

	Tile *getTile(unsigned int index);
	Tileset *getTs();
	int getSize();
};

enum TileType { DEFAULT=1, RANDOMIZED=2, ANIMATED=3, TRANSITIONAL=4 };

enum Orientation { TOP=1, RIGHT=2, BOTTOM=3, LEFT=4 };

struct nStream: public std::streambuf
{
	void overflow(char c)
	{
	}
};
