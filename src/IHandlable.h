#ifndef _BOMBERMAN_IHANDLABLE_H_
#define _BOMBERMAN_IHANDLABLE_H_

#include "Globals.h"

/*! \brief Interface implémentée par chaque classe qui a des évènements individuels à gérer
 */
class IHandlable
{
public:

	/*! \brief contrat de l'interface : une classe fille devra implémenter cette méthode en fonction des évènements qui peuvent lui être liés
	 *  \param event évènement utilisateur
	 *  \param args éventuels arguments dont on a besoin
	 */
	virtual void manageEvents(sf::Event &event, void *args=NULL) = 0;
};

#endif //_BOMBERMAN_IHANDLABLE_H_
