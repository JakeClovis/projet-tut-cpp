#ifndef _BOMBERMAN_IDRAWABLE_H_
#define _BOMBERMAN_IDRAWABLE_H_

#include "Globals.h"
#include "TileSystem.h"
#include "GameWindow.h"

/*! \brief Interface implemented by every class that can be drawn
 */
class IDrawable
{
protected:

	TileSystem *m_tilesys; //!< Any drawable object has a TileSystem

public:

	IDrawable(TileSystem *tilesys);
	/*! \brief abstract class that the daughter class will implements, depending of how it's drawn
	 * \param window pointer to the window on which the object will be drawn
	 */
	virtual void draw(GameWindow* window) = 0;
};

#endif //_BOMBERMAN_IDRAWABLE_H_
