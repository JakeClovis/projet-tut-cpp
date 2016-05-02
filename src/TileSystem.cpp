#include "TileSystem.h"

TileSystem::TileSystem(Tileset *ts) : m_ts(ts)
{
	cout << "** Creating the TileSystem " << this << " with the Tileset " << ts << endl;
}

Tileset *TileSystem::getTs()
{
	return m_ts;
}
