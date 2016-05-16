#include "Bomb.h"

Bomb::Bomb(TileSystem *tilesys, sf::Vector2f center, sf::Vector2f position, int health, Player *player, sf::Time duration): Entity(tilesys, {}, center, position, health), m_duration(duration), m_player(player)
{
}

void Bomb::updateState(Controller *controller, sf::Time &elapsed, Tilemap *world)
{
	float timeBetweenFrames = -(m_timeAlive.getElapsedTime().asSeconds()-m_maxHealth*m_duration.asSeconds())/10;
	if(m_watcher.getElapsedTime().asSeconds() > ((m_tick==0)?timeBetweenFrames:0.05))
	{
		m_watcher.restart();
		m_tick++;
		if(m_tick>=m_tilesys->getTile(1)->getSpriteCount())
		{
			m_tick=0;
		}
	}

	if((m_health>0) && (m_timeAlive.getElapsedTime().asSeconds() >= (m_maxHealth-m_health+1)*m_duration.asSeconds()))
		m_health--;

	if(m_health == 0)
	{
		controller->notifyUpdate();
	}
}

void Bomb::draw(GameWindow *window)
{
	float offsetX = (m_tilesys->getTs()->getDisplayWidth()/(float)m_tilesys->getTs()->getWidth())*m_center.x;
	float offsetY = (m_tilesys->getTs()->getDisplayHeight()/(float)m_tilesys->getTs()->getHeight())*m_center.y;
	window->draw(*(m_tilesys->getTile(1)->getSprite(m_tick, m_position.x-offsetX, m_position.y-offsetY)));
}

Player *Bomb::getPlayer()
{
	return m_player;
}
