#ifndef _BOMBERMAN_CONTROLLER_H_
#define _BOMBERMAN_CONTROLLER_H_

#include <SFML/Audio.hpp>

#include "Globals.h"
#include "GameWindow.h"
#include "Tileset.h"
#include "TileSystem.h"
#include "ResourceAllocator.h"

/*! \brief classe abstraite des contrôleurs de jeu
 *  
 *  Un contrôleur est la partie décisionnelle du modèle MVC : il récupère les données du modèle, gère les évènements utilisateur, et programme la mise à jour de la vue.
 */
class Controller
{
protected:

	GameWindow *m_window; //!< la vue que le contrôleur gère
	map<string, sf::Texture*> m_textures; //!< les textures que le contrôleur contient, référencées par un nom
	map<string, sf::Font*> m_fonts; //!< les fontes que le contrôleur contient, référencées par un nom
	map<string, Tileset*> m_tilesets; //!< les Tileset que le contrôleur contient, référencées par un nom
	map<string, TileSystem*> m_tilesystems; //!< les TileSystem que le contrôleur contient, référencées par un nom
	map<string, sf::Music*> m_musics; //!< les musiques que le contrôleur contient, référencées par un nom
	/*! \brief fonction technique contenant la routine de gestion des évènements utilisateurs
	 */
	virtual void manageEvents() = 0;

public:

	/*! \brief crée un contrôleur
	 *
	 *  Habituellement, la construction d'un contrôleur est aussi la phase d'initialisation des ressources, au moyen des méthodes de la classe statique ResourceAllocator.
	 *  \param window la vue que le contrôleur gère
	 */
	Controller(GameWindow *window);
	/*! \brief met fin au contrôleur
	 *
	 *  Il faut libérer les ressources du contrôleur à ce moment là. Attention à n'en oublier aucune pour éviter les fuites de mémoire.
	 */
	virtual ~Controller();
	/*! \brief démarre le contrôleur
	 *
	 *  Cette méthode doit contenir la boucle d'évènements. Ainsi, cette méthode ne se termine que quand le moment est venu de cesser ses activités (par exemple lorsque l'on ferme la vue qu'il gère, ou lorsque la partie se termine...).
	 */
	virtual void start() = 0;
};

#endif //_BOMBERMAN_CONTROLLER_H_
