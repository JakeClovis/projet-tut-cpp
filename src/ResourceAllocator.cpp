#include "ResourceAllocator.h"

void ResourceAllocator::allocateTexture(map<string, sf::Texture*> &m, const string index, const string path)
{
	sf::Texture *t = new sf::Texture();
	cout << " * Loading texture " << t << " from " << path << endl;
	if(!t->loadFromFile(path))
	{
		cerr << "(X)FATAL:" << path << ": unable to load file" << endl;
		exit(TEXTURE_ERROR);
	}
	
	if(m.insert(pair<string, sf::Texture*>(index, t)).second == false)
	{
		cout << "(!)WARNING:" << index << " is an already existing index in the map of textures (insertion of " << t << " ommitted)" << endl;
		delete t;
	}
}

void ResourceAllocator::allocateFont(map<string, sf::Font*> &m, const string index, const string path)
{
	sf::Font *f = new sf::Font();
	cout << " * Loading font " << f << " from " << path << endl;
	if(!f->loadFromFile(path))
	{
		cerr << "(X)FATAL:" << path << ": unable to load file" << endl;
		exit(FONT_ERROR);
	}
	
	if(m.insert(pair<string, sf::Font*>(index, f)).second == false)
	{
		cout << "(!)WARNING:" << index << " is an already existing index in the map of fonts (insertion of " << f << " ommitted)" << endl;
		delete f;
	}
}

void ResourceAllocator::allocateTileset(map<string, Tileset*> &m, const string index, Tileset *t)
{
	if(m.insert(pair<string, Tileset*>(index, t)).second == false)
	{
		cout << "(!)WARNING:" << index << " is an already existing index in the map of Tilesets (insertion of " << t << " ommitted)" << endl;
		delete t;
	}
}

void ResourceAllocator::allocateTileSystem(map<string, TileSystem*> &m, const string index, Tileset *t)
{
	TileSystem *ts = new TileSystem(t);
	if(m.insert(pair<string, TileSystem*>(index, ts)).second == false)
	{
		cout << "(!)WARNING:" << index << " is an already existing index in the map of TileSystems (insertion of " << ts << " ommitted)" << endl;
		delete t;
	}
}

void ResourceAllocator::allocateMusic(map<string, sf::Music*> &m, const string index, const string path, bool isLoop)
{
	sf::Music *music = new sf::Music();
	cout << " * Loading music " << music << " from " << path << endl;
	if(!music->openFromFile(path))
	{
		cerr << "(x)FATAL:" << path << ": unable to open file" << endl;
		exit(MUSIC_ERROR);
	}

	music->setLoop(isLoop);

	if(m.insert(pair<string, sf::Music*>(index, music)).second == false)
	{
		cout << "(!)WARNING:" << index << " is an already existing index in the map of musics (insertion of " << music << " ommitted)" << endl;
		delete music;
	}
}
