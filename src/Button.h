#ifndef _BOMBERMAN_BUTTON_H_
#define _BOMBERMAN_BUTTON_H_

#include "Globals.h"
#include "IDrawable.h"
#include "IHandlable.h"
#include <SFML/Graphics/Rect.hpp>

/*! \brief gestion de boutons cliquables
 */
class Button: public sf::IntRect, public IDrawable, public IHandlable
{
protected:

	sf::Text m_text; //!< texte affiché par le bouton
	void (*m_callback)(void*); //!< fonction de callback (à déclencher en cas de clic)

public:

	/*! \brief crée un bouton avec les paramètres renseignés
	 *  \param x abscisse du bouton 
	 *  \param y ordonnée du bouton
	 *  \param tilesys TileSystem utilisé par le bouton
	 *  \param text légende du bouton
	 *  \param font fonte de caractère de la légende
	 *  \param callback action à entreprendre en cas de clic du bouton
	 */
	Button(TileSystem *tilesys, int x, int y, string text, sf::Font *font, void(*callback)(void*));
	virtual ~Button();
	/*! \brief combiné d'appel pour la fonction de callback
	 *  \param args argument générique de la fonction de callback (utiliser une structure si la fonction de callback a besoin de plusieurs paramètres)
	 */
	void callback(void* args);
	void draw(GameWindow*);
	void manageEvents(sf::Event &event, void *args=NULL);
	
};

#endif //_BOMBERMAN_BUTTON_H_
