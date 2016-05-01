#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include "Game.h"

#define DEBUG_MODE true
#define G_VERSION "dev"
#define G_AUTHORS "Guillaume JORANDON & Clément SIMON"

using namespace std;

/**
 * A structure that describes a null stream buffer (quite the equivalent of /dev/null on *nix systems)
 */
struct nStream: public std::streambuf
{
	void overflow(char c)
	{
	}
};

/**
 * Prints the help on the standard output
 */
void displayHelp(const char *name)
{
	cout << "Bomberman clone v" << G_VERSION << " - " << G_AUTHORS << endl <<
			"Usage: " << name << " <[option(s)]" << endl <<
			"Options: " << endl <<
			" -h\t\tDisplays this current help and exits" << endl <<
			" -v\t\tVerbose output" << endl;
}

/**
 * Reads options from command line then launches the game
 */
int main(int argc, char *argv[])
{
	nStream nullStream;
	Game *game = NULL;
	streambuf *coutBackup = cout.rdbuf(&nullStream);
	int options, tileSize = 0;

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
			try
			{
				tileSize = stoi(string(optarg));
			}
			catch(invalid_argument const&e)
			{
				cerr << "stoi(\"" << optarg << "\"): invalid_argument exception" << endl;
				cerr << "Try " << argv[0] << " -h for help." << endl;
				exit(1);
			}
			break;
		default: //invalid option
			cout.rdbuf(coutBackup);
			cerr << "Try " << argv[0] << " -h for help." << endl;
			exit(1);
	}

	cout << "Launching Bomberman clone v" << G_VERSION << "..." << endl <<
		   "Crafted by " << G_AUTHORS << endl;

	if(tileSize > 0)
		game = new Game(tileSize);
	else
		game = new Game();

	game->start();

	delete game;

	cout.rdbuf(coutBackup); //don't forget to restore standard output in order to avoid segmentation fault
	return 0;
}
