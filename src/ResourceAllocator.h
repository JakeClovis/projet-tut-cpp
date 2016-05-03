#ifndef _BOMBERMAN_RESOURCE_ALLOCATOR_H_
#define _BOMBERMAN_RESOURCE_ALLOCATOR_H_

#include "Globals.h"
#include "Tileset.h"
#include <string>

class ResourceAllocator
{
public:

	static void allocateTexture(map<string, sf::Texture*>&, const string, const string);
	static void allocateTileset(map<string, Tileset*>&, const string, Tileset*);
};

#endif //_BOMBERMAN_RESOURCE_ALLOCATOR_H_
