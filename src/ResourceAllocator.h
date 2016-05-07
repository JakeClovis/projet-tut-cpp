#ifndef _BOMBERMAN_RESOURCE_ALLOCATOR_H_
#define _BOMBERMAN_RESOURCE_ALLOCATOR_H_

#include <SFML/Audio.hpp>
#include <string>
#include "Globals.h"
#include "Tileset.h"
#include "TileSystem.h"

/*! \brief static class to store resources in referenced lists
 */
class ResourceAllocator
{
public:

	/*! \brief allocates a sf::Texture
	 *  \param m pointer to the referenced list that will store the resource
	 *  \param index string index in the list
	 *  \param path path to the resource
	 */
	static void allocateTexture(map<string, sf::Texture*> &m, const string index, const string path);
	/*! \brief allocates a sf::Music
	 *  \param m pointer to the referenced list that will store the resource
	 *  \param index string index in the list
	 *  \param path path to the resource
	 *  \param isLoop true if the sf::Music is a loop song
	 */
	static void allocateMusic(map<string, sf::Music*> &m, const string index, const string path, bool isLoop=false);
	/*! \brief allocates a sf::Font
	 *  \param m pointer to the referenced list that will store the resource
	 *  \param index string index in the list
	 *  \param path path to the resource
	 */
	static void allocateFont(map<string, sf::Font*> &m, const string index, const string path);

	/*! \brief allocates a Tileset
	 *  \param m pointer to the referenced list that will store the resource
	 *  \param index string index in the list
	 *  \param t pointer to the Tileset to store
	 */
	static void allocateTileset(map<string, Tileset*> &m, const string index, Tileset *t);
	/*! \brief allocates a TileSystem
	 *  \param m pointer to the referenced list that will store the resource
	 *  \param index string index in the list
	 *  \param t pointer to the Tileset that will be used by the TileSystem
	 */
	static void allocateTileSystem(map<string, TileSystem*> &m, const string index, Tileset *t);
};

#endif //_BOMBERMAN_RESOURCE_ALLOCATOR_H_
