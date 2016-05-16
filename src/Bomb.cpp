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
				cout << logicalPos.x << ":" << logicalPos.y << endl;
				for(unsigned int i = 1 ; i <= m_blastRadius ; i++)
				{
					if(!((MapTile*)world->getTile(logicalPos.x, logicalPos.y-i))->isCollidable() && !hit[0])
					{
						m_maxSize[0]++;
					}
					else
						hit[0] = true;
					if(!((MapTile*)world->getTile(logicalPos.x, logicalPos.y+i))->isCollidable() && !hit[2])
					{
						m_maxSize[2]++;
					}
					else
						hit[2] = true;
					if(!((MapTile*)world->getTile(logicalPos.x+i, logicalPos.y))->isCollidable() && !hit[1])
					{
						m_maxSize[1]++;
					}
					else
						hit[1] = true;
					if(!((MapTile*)world->getTile(logicalPos.x-i, logicalPos.y))->isCollidable() && !hit[3])
					{
						m_maxSize[3]++;
					}
					else
						hit[3] = true;
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

		if(m_timeAlive.getElapsedTime().asSeconds() >= SPEED_FACTOR*0.17)
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
