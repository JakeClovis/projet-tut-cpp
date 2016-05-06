#ifndef _BOMBERMAN_IDRAWABLE_H_
#define _BOMBERMAN_IDRAWABLE_H_

#include "Globals.h"
#include "TileSystem.h"
#include "GameWindow.h"

class IDrawable
{
protected:

	TileSystem *m_tilesys;

public:

	virtual void draw(GameWindow*) = 0;
};

#endif //_BOMBERMAN_IDRAWABLE_H_
