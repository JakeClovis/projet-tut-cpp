#include "Globals.h"
#include "Menu.h"

/*! \brief a structure that describes a null stream buffer (quite the equivalent of /dev/null on *nix systems)
 */
struct nStream: public std::streambuf
{
	/*! \brief overflow function, won't do anything because it's a null buffer
	 *  \param c nevermind, it's not important
	 */
	void overflow(char c)
	{
	}
};

/*! \brief prints the help on the standard output
 *  \param name corresponds to argv[0]
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

/*! \brief main file, reads the command line and launches the game
 *  \param argc arguments count (o rly?)
 *  \param argv arguments from the command line (O, RLY???)
 */
int main(int argc, char *argv[])
{
	nStream nullStream;
	Menu *mainController = NULL; // the game instance
	GameWindow window; // main window
	streambuf *coutBackup = cout.rdbuf(&nullStream);
	int options, tileSize = 0;

	srand(time(NULL));

	if(DEBUG_MODE) //Forces the verbose mode (for debugging purposes)
		cout.rdbuf(coutBackup);

	while((options = getopt(argc, argv, "hvs:")) != -1)
		switch(options)
		{
		case 'h': //help
			cout.rdbuf(coutBackup);
			displayHelp(argv[0]);
			exit(0);
		case 'v': //verbose mode
			cout.rdbuf(coutBackup);
			break;
		case 's': //custom tile size
				tileSize = atoi(optarg);
				if(tileSize <= 0)
				{
					cerr << "atoi(\"" << optarg << "\"): incorrect value" << endl;
					cerr << "Try " << argv[0] << " -h for help." << endl;
					exit(GENERIC_ERROR);
				}
			break;
		default: //invalid option
			cout.rdbuf(coutBackup);
			cerr << "Try " << argv[0] << " -h for help." << endl;
			exit(GENERIC_ERROR);
		}

	cout << "Launching Bomberman clone v" << G_VERSION << "..." << endl <<
		   "Crafted by " << G_AUTHORS << endl;


	if(tileSize > 0)
		window.create(tileSize, 17, 13);
	else
		window.create(17, 13);

	mainController = new Menu(&window);
	mainController->start();

	delete mainController;

	cout.rdbuf(coutBackup); //don't forget to restore standard output in order to avoid segmentation fault
	return 0;
}
