#include "Bomb.h"

Bomb::Bomb(TileSystem *tilesys, sf::Vector2f center, sf::Vector2f position, int health, Player *player, sf::Time duration, unsigned int blastRadius): Entity(tilesys, {}, center, position, health), m_duration(duration), m_player(player), m_blastRadius(blastRadius)
{
}

void Bomb::updateState(Controller *controller, sf::Time &elapsed, Tilemap *world)
{
	if(m_health > 0)
	{
		float timeBetweenFrames = -(m_timeAlive.getElapsedTime().asSeconds()-m_maxHealth*m_duration.asSeconds())/30;
		if(m_watcher.getElapsedTime().asSeconds() > ((m_tick==0)?timeBetweenFrames*SPEED_FACTOR:SPEED_FACTOR*0.017))
		{
			m_watcher.restart();
			m_tick++;
			if(m_tick>=m_tilesys->getTile(1)->getSpriteCount())
			{
				m_tick=0;
			}
		}
	
		if(m_timeAlive.getElapsedTime().asSeconds() >= (m_maxHealth-m_health+1)*m_duration.asSeconds())
		{
			m_health--;
			if(m_health==0)
			{
				m_timeAlive.restart();
				m_watcher.restart();
				m_tick = 0;
				for(int i = 0 ; i < 4 ; i++) m_maxSize[i] = 0;
				sf::Vector2i logicalPos = world->toTileCoord(m_position);
				bool hit[] = {false, false, false, false};
				for(unsigned int i = 1 ; i <= m_blastRadius ; i++)
				{
					if(!((MapTile*)world->getTile(logicalPos.x, logicalPos.y-i))->isCollidable() && !hit[0])
					{
						m_maxSize[0]++;
					}
					else if(!hit[0])
					{
						hit[0] = true;
							world->attemptDestruction(logicalPos.x, logicalPos.y-i);
					}
					if(!((MapTile*)world->getTile(logicalPos.x, logicalPos.y+i))->isCollidable() && !hit[2])
					{
						m_maxSize[2]++;
					}
					else if(!hit[2])
					{
						hit[2] = true;
							world->attemptDestruction(logicalPos.x, logicalPos.y+i);
					}
					if(!((MapTile*)world->getTile(logicalPos.x+i, logicalPos.y))->isCollidable() && !hit[1])
					{
						m_maxSize[1]++;
					}
					else if(!hit[1])
					{
						hit[1] = true;
							world->attemptDestruction(logicalPos.x+i, logicalPos.y);
					}
					if(!((MapTile*)world->getTile(logicalPos.x-i, logicalPos.y))->isCollidable() && !hit[3])
					{
						m_maxSize[3]++;
					}
					else if(!hit[3])
					{
						hit[3] = true;
							world->attemptDestruction(logicalPos.x-i, logicalPos.y);
					}
				}
			}
		}
	}
	else if(m_health == 0)
	{
		if(m_watcher.getElapsedTime().asSeconds() > SPEED_FACTOR*0.005)
		{
			m_watcher.restart();
			m_tick++;
			if(m_tick>=m_tilesys->getTile(2)->getSpriteCount())
			{
				m_tick = m_tilesys->getTile(2)->getSpriteCount()-2;
			}
		}
		
		if(Game *g = dynamic_cast<Game*>(controller))
		{
			sf::Vector2i logicalPos = world->toTileCoord(m_position);
			for(int i = 1 ; i <= 2 ; i++)
			{
				Player *p = g->getPlayer(i);
				bool hasBeenHit = false;

				if(p->isOnCoord(logicalPos.x, logicalPos.y, world))
				{
					p->hit();
					hasBeenHit = true;
				}
				if(!hasBeenHit)
				{
					for(unsigned int j = 1 ; j <= m_blastRadius ; j++)
					{
						if((p->isOnCoord(logicalPos.x, logicalPos.y-j, world) && j <= m_maxSize[0]) ||
						   (p->isOnCoord(logicalPos.x, logicalPos.y+j, world) && j <= m_maxSize[2]) ||
						   (p->isOnCoord(logicalPos.x-j, logicalPos.y, world) && j <= m_maxSize[3]) ||
						   (p->isOnCoord(logicalPos.x+j, logicalPos.y, world) && j <= m_maxSize[1]))
						{
							hasBeenHit = true;
							p->hit();
							break;
						}
					}
				}
			}
		}

		if(m_timeAlive.getElapsedTime().asSeconds() >= SPEED_FACTOR*0.24)
			m_health--;
	}	
	else
	{
		controller->notifyUpdate();
	}
}

void Bomb::draw(GameWindow *window)
{
	float offsetX = (m_tilesys->getTs()->getDisplayWidth()/(float)m_tilesys->getTs()->getWidth())*m_center.x;
	float offsetY = (m_tilesys->getTs()->getDisplayHeight()/(float)m_tilesys->getTs()->getHeight())*m_center.y;
	window->draw(*(m_tilesys->getTile(m_health>0?1:2)->getSprite(m_tick, m_position.x-offsetX, m_position.y-offsetY)));
	
	if(m_health==0)
	{
		for(unsigned int i = 1 ; i <= m_blastRadius ; i++)
		{
			if(i<=m_maxSize[0])
				window->draw(*(m_tilesys->getTile((i==m_blastRadius)?3:7)->getSprite(m_tick, m_position.x-offsetX, m_position.y-offsetY-i*m_tilesys->getTs()->getDisplayHeight())));
			if(i<=m_maxSize[2])
				window->draw(*(m_tilesys->getTile((i==m_blastRadius)?5:7)->getSprite(m_tick, m_position.x-offsetX, m_position.y-offsetY+i*m_tilesys->getTs()->getDisplayHeight())));
			if(i<=m_maxSize[3])
				window->draw(*(m_tilesys->getTile((i==m_blastRadius)?6:8)->getSprite(m_tick, m_position.x-offsetX-i*m_tilesys->getTs()->getDisplayWidth(), m_position.y-offsetY)));
			if(i<=m_maxSize[1])
				window->draw(*(m_tilesys->getTile((i==m_blastRadius)?4:8)->getSprite(m_tick, m_position.x-offsetX+i*m_tilesys->getTs()->getDisplayWidth(), m_position.y-offsetY)));
		}
	}
}

Player *Bomb::getPlayer()
{
	return m_player;
}
