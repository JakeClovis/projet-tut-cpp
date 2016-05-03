#include "ResourceAllocator.h"

void ResourceAllocator::allocateTexture(map<string, sf::Texture*> &m, const string index, const string path)
{
	sf::Texture *t = new sf::Texture();
	cout << " * Loading texture " << t << endl;
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

void ResourceAllocator::allocateTileset(map<string, Tileset*> &m, const string index, Tileset *t)
{
	if(m.insert(pair<string, Tileset*>(index, t)).second == false)
	{
		cout << "(!)WARNING:" << index << " is an already existing index in the map of tilesets (insertion of " << t << " ommitted)" << endl;
		delete t;
	}
}
