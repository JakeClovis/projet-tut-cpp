#ifndef _BOMBERMAN_GLOBALS_H_
#define _BOMBERMAN_GLOBALS_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <unistd.h>

#define DEFAULT_TILE_SIZE 70
#define DEBUG_MODE true
#define G_VERSION "dev"
#define G_AUTHORS "Guillaume JORANDON & Clément SIMON"

#define GENERIC_ERROR 1 //Problème générique (lecture d'arguments de la ligne de commande, etc.)
#define TEXTURE_ERROR 2 //Problème lors du chargement d'une texture

using namespace std;

#endif //_BOMBERMAN_GLOBALS_H_
