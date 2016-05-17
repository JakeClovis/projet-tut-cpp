#ifndef _BOMBERMAN_GLOBALS_H_
#define _BOMBERMAN_GLOBALS_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <unistd.h>
#include <ctime>

#define DEFAULT_TILE_SIZE 50 //default tile size
#define DEBUG_MODE true //true will force the -v parameter
#define G_VERSION "dev" //version
#define G_AUTHORS "Guillaume JORANDON & Clément SIMON" //authors

#define SPEED_FACTOR 3 //global speed factor of the Entities

#define ABS(X) (((X)<0?(-X):(X))) //absolute value of X
#define SGN(X) (((X)>0?(true):(false))) //1 if X>0, -1 otherwise

#define GENERIC_ERROR 1 //Generic problem (arguments from the command line, etc.)
#define TEXTURE_ERROR 2 //Problem in Texture allocation
#define TILESET_ERROR 3 //Problem in Tileset allocation
#define MUSIC_ERROR 4 //Problem in Music loading
#define FONT_ERROR 5 //Problem in Font loading

/*! \brief différents types de Tile
 */
enum TileType { DEFAULT=1, RANDOMIZED=2, ANIMATED=3, TRANSITIONAL=4 };
/*! \brief orientations des entités vivantes
 */
enum Orientation { TOP=1, RIGHT=2, BOTTOM=3, LEFT=4 };

using namespace std;

#endif //_BOMBERMAN_GLOBALS_H_
