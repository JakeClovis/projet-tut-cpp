#include "Player.h"

Player::Player(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health, vector<sf::Keyboard::Key> controls, TileSystem *bombTilesys): LivingEntity(tilesys, bBoxes, center, position, health), m_blastPower(2), m_bombCount(1), m_bombInventory(1), m_bombHasBeenDropped(false), m_bombTilesys(bombTilesys), m_controls(controls)
{
}

void Player::manageEvents(sf::Event &event, void *args)
{
	vector<void*> *a = (vector<void*>*) args;

	GameWindow *w = (GameWindow*)((*a)[0]);
	Tilemap *tm = (Tilemap*)((*a)[1]);
	vector<Entity*> *l = (vector<Entity*>*)((*a)[2]);

	//on modifie la vitesse du joueur en fonction de la touche sur laquelle il appuie
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

	//Si on vient d'appuyer sur le bouton de largage de bombe
	if(sf::Keyboard::isKeyPressed(m_controls[4]) && !m_bombHasBeenDropped)
	{
		if(m_bombInventory > 0) //si on a une bombe en inventaire
		{
			sf::Vector2i logicalPosToDrop = tm->toTileCoord(m_position); //on récupère la position logique à laquelle poser la bombe
			sf::Vector2f posToDrop = {(float) (tm->getTileSystem()->getTs()->getDisplayWidth()*logicalPosToDrop.x), (float) (tm->getTileSystem()->getTs()->getDisplayHeight()*logicalPosToDrop.y)}; //on la convertit en position réelle
			bool canDrop = true;
			for(unsigned int i = 0 ; i < l->size() ; i++)
			{
				if((*l)[i]->getPosition() == posToDrop) //on vérifie qu'il n'y a pas déjà une bombe là où on veut lâcher la notre
				{
					if(dynamic_cast<Bomb*>((*l)[i]))
					{
						canDrop = false;
						break;
					}
				}
			}

			if(canDrop) //si on peut poser la bombe
			{
				m_bombInventory--;
				dropBomb(posToDrop, l);
			}
			m_bombHasBeenDropped = true;
		}
	}
	else if(!sf::Keyboard::isKeyPressed(m_controls[4]) && m_bombHasBeenDropped) //si on vient de relâcher le bouton de largage de bombe
		m_bombHasBeenDropped = false;
}

void Player::dropBomb(sf::Vector2f pos, vector<Entity*> *list)
{
	list->push_back((Entity*)new Bomb(m_bombTilesys, {0, 0}, pos, 4, this, sf::seconds(SPEED_FACTOR*(1/(float)7)), m_blastPower)); //on ajoute une bombe à la liste d'entités
}

void Player::notifyExplosion()
{
	if(m_bombInventory < m_bombCount) m_bombInventory++; //on remet une bombe en inventaire, si l'inventaire n'est pas plein
}

void Player::hit()
{
	if(m_health>0) m_health--; //on fait prendre au joueur un coup si il peut encore
}

bool Player::isOnCoord(unsigned int i, unsigned int j, Tilemap *world)
{
	//on calcule les coordonnées réelles de la boite de collision
	float offsetX = (m_tilesys->getTs()->getDisplayWidth()/(float)m_tilesys->getTs()->getWidth())*m_center.x;
	float offsetY = (m_tilesys->getTs()->getDisplayHeight()/(float)m_tilesys->getTs()->getHeight())*m_center.y;
	float displayLeft = (m_tilesys->getTs()->getDisplayWidth()/(float)m_tilesys->getTs()->getWidth())*m_bBoxes[m_orientation].left;
	float displayTop = (m_tilesys->getTs()->getDisplayHeight()/(float)m_tilesys->getTs()->getHeight())*m_bBoxes[m_orientation].top;
	float displayWidth = (m_tilesys->getTs()->getDisplayWidth()/(float)m_tilesys->getTs()->getWidth())*m_bBoxes[m_orientation].width;
	float displayHeight = (m_tilesys->getTs()->getDisplayHeight()/(float)m_tilesys->getTs()->getHeight())*m_bBoxes[m_orientation].height;

	sf::Vector2i topMin = world->toTileCoord(sf::Vector2f(m_position.x-offsetX+displayLeft, m_position.y-offsetY+displayTop));
	sf::Vector2i bottomMax = world->toTileCoord(sf::Vector2f(m_position.x-offsetX+displayLeft+displayWidth, m_position.y-offsetY+displayTop+displayHeight));
	
	//on vérifie si oui ou non la boite de collision intersecte avec la coordonnée passée en paramètre
	for(unsigned int it = topMin.x ; it <= (unsigned int) bottomMax.x ; it++)
	{
		for(unsigned int jt = topMin.y ; jt <= (unsigned int) bottomMax.y ; jt++)
		{
			if((it==i)&&(jt==j))
			{
				return true;
			}
		}
	}
	return false;
}
