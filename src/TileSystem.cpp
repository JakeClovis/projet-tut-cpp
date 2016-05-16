#include "TileSystem.h"

TileSystem::TileSystem(Tileset *ts) : m_ts(ts)
{
	cout << "** Creating the TileSystem " << this << " with the Tileset " << ts << endl;
}

Tileset *TileSystem::getTs()
{
	return m_ts;
}

template<>
void TileSystem::registerTile<MapTile>(unsigned int index, int i, int j, TileType ty, bool c, bool b)
{
	MapTile *t = m_ts->createTile<MapTile>(i, j, ty, c, b);
	if(index != 0)
	{
		cout << "** Registering the Tile " << t << " in the TileSystem " << this << endl;
		if(m_tilesList.insert(pair<unsigned int, Tile*>(index, (Tile*) t)).second == false)
			cout << "(!)WARNING:" << index << " is an already existing index in the TileSystem " << this << " (insertion of " << t << " ommitted)" << endl;
	}
	else
		cout << "(!)WARNING:couldn't register " << t << " in the TileSystem " << this << " (0 is a special index)" << endl;
}

template<>
void TileSystem::registerTile<MapTile>(unsigned int index, vector<int> i, vector<int> j, TileType ty, bool c, bool b)
{
	MapTile *t = m_ts->createTile<MapTile>(i, j, ty, c, b);
	if(index != 0)
	{
		cout << "** Registering the Tile " << t << " in the TileSystem " << this << endl;
		if(m_tilesList.insert(pair<unsigned int, Tile*>(index, (Tile*) t)).second == false)
			cout << "(!)WARNING:" << index << " is an already existing index in the TileSystem " << this << " (insertion of " << t << " ommitted)" << endl;
	}
	else
		cout << "(!)WARNING:couldn't register " << t << " in the TileSystem " << this << " (0 is a special index)" << endl;
}

Tile *TileSystem::getTile(unsigned int index)
{
	if(index == 0) //index vide
	{
		return NULL;
	}
	map<unsigned int, Tile*>::iterator element;
	element = m_tilesList.find(index);
	if(element != m_tilesList.end())
	{
		return element->second;
	}
	else
	{
		cout << "(X)SEVERE:" << index << " is an unexisting index in the TileSystem " << this << endl;
		return NULL;
	}
}

TileSystem::~TileSystem()
{
	cout << "** Deleting the TileSystem " << this << endl;
	for (map<unsigned int, Tile*>::iterator element=m_tilesList.begin() ; element != m_tilesList.end() ; element++)
	{
		delete element->second;
	}
}

int TileSystem::getSize()
{
	return m_tilesList.size();
}
