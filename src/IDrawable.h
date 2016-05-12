#ifndef _BOMBERMAN_IDRAWABLE_H_
#define _BOMBERMAN_IDRAWABLE_H_

#include "Globals.h"
#include "TileSystem.h"
#include "GameWindow.h"

/*! \brief Interface implémentée par chaque classe qui peut être affichée
 */
class IDrawable
{
protected:

	TileSystem *m_tilesys; //!< Un objet dessinable a toujours un TileSystem

public:

	/*! \brief constructeur à appeler lors de la construction des classes filles pour assigner une valeur au pointeur sur le TileSystem du IDrawable
	 */
	IDrawable(TileSystem *tilesys);
	/*! \brief contrat de l'interface : une classe fille devra implémenter cette méthode en fonction de comment elle est affichée
	 * \param window fenêtre sur laquelle on dessine
	 */
	virtual void draw(GameWindow* window) = 0;
};

#endif //_BOMBERMAN_IDRAWABLE_H_
