#include "Player.h"

Player::Player(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health, vector<sf::Keyboard::Key> controls, TileSystem *bombTilesys): LivingEntity(tilesys, bBoxes, center, position, health), m_blastPower(2), m_bombCount(1), m_bombInventory(1), m_bombHasBeenDropped(false), m_bombTilesys(bombTilesys)
, m_controls(controls){
}

void Player::manageEvents(sf::Event &event, void *args)
{
	vector<void*> *a = (vector<void*>*) args;

	GameWindow *w = (GameWindow*)((*a)[0]);
	Tilemap *tm = (Tilemap*)((*a)[1]);
	vector<Entity*> *l = (vector<Entity*>*)((*a)[2]);

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

	if(sf::Keyboard::isKeyPressed(m_controls[4]) && !m_bombHasBeenDropped)
	{
		if(m_bombInventory > 0)
		{
			m_bombInventory--;
			sf::Vector2i logicalPosToDrop = tm->toTileCoord(m_position);
			sf::Vector2f posToDrop = {(float) (tm->getTileSystem()->getTs()->getDisplayWidth()*logicalPosToDrop.x), (float) (tm->getTileSystem()->getTs()->getDisplayHeight()*logicalPosToDrop.y)};

			dropBomb(posToDrop, l);
			m_bombHasBeenDropped = true;
		}
	}
	else if(!sf::Keyboard::isKeyPressed(m_controls[4]) && m_bombHasBeenDropped)
		m_bombHasBeenDropped = false;
}

void Player::dropBomb(sf::Vector2f pos, vector<Entity*> *list)
{
	list->push_back((Entity*)new Bomb(m_bombTilesys, {0, 0}, pos, 4, this, sf::seconds(SPEED_FACTOR*(1/(float)9)), m_blastPower));
}

void Player::notifyExplosion()
{
	if(m_bombInventory < m_bombCount) m_bombInventory++;
}
