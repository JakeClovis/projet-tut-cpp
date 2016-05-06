#ifndef _BOMBERMAN_RESOURCE_ALLOCATOR_H_
#define _BOMBERMAN_RESOURCE_ALLOCATOR_H_

#include <SFML/Audio.hpp>
#include <string>
#include "Globals.h"
#include "Tileset.h"
#include "TileSystem.h"

class ResourceAllocator
{
public:

	static void allocateTexture(map<string, sf::Texture*>&, const string, const string);
	static void allocateMusic(map<string, sf::Music*>&, const string, const string, bool=false);
	static void allocateFont(map<string, sf::Font*>&, const string, const string);

	static void allocateTileset(map<string, Tileset*>&, const string, Tileset*);
	static void allocateTileSystem(map<string, TileSystem*>&, const string, Tileset*);
};

#endif //_BOMBERMAN_RESOURCE_ALLOCATOR_H_
