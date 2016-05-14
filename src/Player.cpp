#include "Player.h"

Player::Player(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health, vector<sf::Keyboard::Key> controls): LivingEntity(tilesys, bBoxes, center, position, health), m_blastPower(1), m_bombCount(1)
, m_controls(controls){
}

void Player::manageEvents(sf::Event &event, void *args)
{
	GameWindow *w = (GameWindow*)args;
	if(sf::Keyboard::isKeyPressed(m_controls[0]))
		setSpeed(sf::Vector2f(0, -SPEED_FACTOR*w->getTileSize()));
	else if(sf::Keyboard::isKeyPressed(m_controls[2]))
		setSpeed(sf::Vector2f(0, SPEED_FACTOR*w->getTileSize()));
	else if(sf::Keyboard::isKeyPressed(m_controls[3]))
		setSpeed(sf::Vector2f(-SPEED_FACTOR*w->getTileSize(), 0));
	else if(sf::Keyboard::isKeyPressed(m_controls[1]))
		setSpeed(sf::Vector2f(SPEED_FACTOR*w->getTileSize(), 0));
	else
		setSpeed(sf::Vector2f(0, 0));
}
