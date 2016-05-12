#ifndef _BOMBERMAN_RESOURCE_ALLOCATOR_H_
#define _BOMBERMAN_RESOURCE_ALLOCATOR_H_

#include <SFML/Audio.hpp>
#include <string>
#include "Globals.h"
#include "Tileset.h"
#include "TileSystem.h"

/*! \brief classe statique chargée de fournir des fonctions d'allocation de ressource
 */
class ResourceAllocator
{
public:

	/*! \brief indexe une texture
	 *  \param m liste référencée qui stockera la ressource
	 *  \param index nom de la ressource
	 *  \param path chemin d'accès de la ressource sur le disque
	 */
	static void allocateTexture(map<string, sf::Texture*> &m, const string index, const string path);
	/*! \brief indexe une musique
	 *  \param m liste référencée qui stockera la ressource
	 *  \param index nom de la ressource
	 *  \param path chemin d'accès de la ressource sur le disque
	 *  \param isLoop vrai si la musique se joue en boucle
	 */
	static void allocateMusic(map<string, sf::Music*> &m, const string index, const string path, bool isLoop=false);
	/*! \brief indexe une fonte
	 *  \param m liste référencée qui stockera la ressource
	 *  \param index nom de la ressource
	 *  \param path chemin d'accès de la ressource sur le disque
	 */
	static void allocateFont(map<string, sf::Font*> &m, const string index, const string path);

	/*! \brief indexe un Tileset
	 *  \param m liste référencée qui stockera la ressource
	 *  \param index nom de la ressource
	 *  \param t Tileset à indexer
	 */
	static void allocateTileset(map<string, Tileset*> &m, const string index, Tileset *t);
	/*! \brief indexe un TileSystem
	 *  \param m liste référencée qui stockera la ressource
	 *  \param index nom de la ressource
	 *  \param t Tileset que le TileSystem utilisera
	 */
	static void allocateTileSystem(map<string, TileSystem*> &m, const string index, Tileset *t);
};

#endif //_BOMBERMAN_RESOURCE_ALLOCATOR_H_
