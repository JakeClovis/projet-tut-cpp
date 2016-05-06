#ifndef _BOMBERMAN_GLOBALS_H_
#define _BOMBERMAN_GLOBALS_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <unistd.h>

#define DEFAULT_TILE_SIZE 70
#define DEBUG_MODE true
#define G_VERSION "dev"
#define G_AUTHORS "Guillaume JORANDON & Clément SIMON"

#define GENERIC_ERROR 1 //Generic problem (arguments from the command line, etc.)
#define TEXTURE_ERROR 2 //Problem in Texture allocation
#define TILESET_ERROR 3 //Problem in Tileset allocation
#define MUSIC_ERROR 4 //Problem in Music loading
#define FONT_ERROR 5 //Problem in Font loading

using namespace std;

#endif //_BOMBERMAN_GLOBALS_H_
