#include "Globals.h"
#include "Menu.h"

/*! \brief une structure qui décrit un stream buffer nul (équivalent en C++ du /dev/null sur les systèmes *nix)
 */
struct nStream: public std::streambuf
{
	/*! \brief fonction d'overflow, ne fait rien car on a un tampon nul
	 *  \param c Regarde-moi dans les yeux. Regarde-moi. On s’en branle, c’est pas important !
	 */
	void overflow(char c)
	{
	}
};

/*! \brief affiche l'aide sur la sortie standard
 *  \param nom de la commande
 */
void displayHelp(const char *name)
{
	cout << "Bomberman clone v" << G_VERSION << " - " << G_AUTHORS << endl <<
			"Usage: " << name << " [option(s)]" << endl <<
			"Options: " << endl <<
			" -h\t\tDisplays this current help and exits" << endl <<
			" -v\t\tVerbose output" << endl <<
			" -s SIZE\tChange the tile size (default: " << DEFAULT_TILE_SIZE << ")" << endl;
}

/*! \brief Fonction principale, lit les arguments de la ligne de commande et lance le jeu
 *  \param argc nombre d'arguments (rly?)
 *  \param argv les arguments de la ligne de commande (O, RLY???)
 */
int main(int argc, char *argv[])
{
	nStream nullStream;
	Menu *mainController = NULL; // l'instance de jeu
	GameWindow window; // fenêtre principale
	streambuf *coutBackup = cout.rdbuf(&nullStream);
	int options, tileSize = 0;

	srand(time(NULL));

	if(DEBUG_MODE) //force le mode verbeux (pour le mode debug)
		cout.rdbuf(coutBackup);

	while((options = getopt(argc, argv, "hvs:")) != -1)
		switch(options)
		{
		case 'h': //aide
			cout.rdbuf(coutBackup);
			displayHelp(argv[0]);
			exit(0);
		case 'v': //mode verbeux
			cout.rdbuf(coutBackup);
			break;
		case 's': //taille de tuile personnalisée
				tileSize = atoi(optarg);
				if(tileSize <= 0)
				{
					cerr << "atoi(\"" << optarg << "\"): incorrect value" << endl;
					cerr << "Try " << argv[0] << " -h for help." << endl;
					exit(GENERIC_ERROR);
				}
			break;
		default: //option invalide
			cout.rdbuf(coutBackup);
			cerr << "Try " << argv[0] << " -h for help." << endl;
			exit(GENERIC_ERROR);
		}

	cout << "Launching Bomberman clone v" << G_VERSION << "..." << endl <<
		   "Crafted by " << G_AUTHORS << endl;


	if(tileSize > 0)
		window.create(tileSize, 17, 14);
	else
		window.create(17, 14);

	mainController = new Menu(&window);
	mainController->start();

	delete mainController;

	cout.rdbuf(coutBackup); //on n'oublie pas de restaurer la sortie standard par défaut pour éviter les segmentation fault
	return 0;
}
