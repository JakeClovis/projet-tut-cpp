#include "LivingEntity.h"

LivingEntity::LivingEntity(TileSystem *tilesys, map<Orientation, sf::IntRect> bBoxes, sf::Vector2f center, sf::Vector2f position, int health): Entity(tilesys, bBoxes, center, position, health)
{
	m_speed.x = 0;
	m_speed.y = 0;
	m_orientation = Orientation::BOTTOM; //L'orientation du joueur est par défaut Orientation::BOTTOM
}

void LivingEntity::setSpeed(sf::Vector2f speed)
{
	m_speed = speed;
}

void LivingEntity::move(sf::Vector2f potential, Tilemap *world)
{
	sf::Vector2f n_position;

	//on calcule les coordonnées réelles de la boite de collision
	float offsetX = (m_tilesys->getTs()->getDisplayWidth()/(float)m_tilesys->getTs()->getWidth())*m_center.x;
	float offsetY = (m_tilesys->getTs()->getDisplayHeight()/(float)m_tilesys->getTs()->getHeight())*m_center.y;
	float displayLeft = (m_tilesys->getTs()->getDisplayWidth()/(float)m_tilesys->getTs()->getWidth())*m_bBoxes[m_orientation].left;
	float displayTop = (m_tilesys->getTs()->getDisplayHeight()/(float)m_tilesys->getTs()->getHeight())*m_bBoxes[m_orientation].top;
	float displayWidth = (m_tilesys->getTs()->getDisplayWidth()/(float)m_tilesys->getTs()->getWidth())*m_bBoxes[m_orientation].width;
	float displayHeight = (m_tilesys->getTs()->getDisplayHeight()/(float)m_tilesys->getTs()->getHeight())*m_bBoxes[m_orientation].height;

	sf::Vector2i topMin = world->toTileCoord(sf::Vector2f(m_position.x+potential.x-offsetX+displayLeft, m_position.y+potential.y-offsetY+displayTop));
	sf::Vector2i bottomMax = world->toTileCoord(sf::Vector2f(m_position.x+potential.x-offsetX+displayLeft+displayWidth, m_position.y+potential.y-offsetY+displayTop+displayHeight));

	bool canMove = false;
	bool xSgn = SGN(potential.x);
	bool ySgn = SGN(potential.y);

	//tant que le vecteur potentiel de déplacement ne change pas de direction et qu'on n'a pas bougé, on répète un test affine de déplacement
	while((SGN(potential.x) == xSgn) && (SGN(potential.y) == ySgn) && !canMove)
	{
		canMove=true;
		//on définit le déplacement hypothétique
		n_position.x = m_position.x + potential.x;
		n_position.y = m_position.y + potential.y;
		//on vérifie que ce déplacement n'engendre pas une collision
		for(unsigned int i = topMin.x ; i <= (unsigned int) bottomMax.x ; i++)
		{
			for(unsigned int j = topMin.y ; j <= (unsigned int) bottomMax.y ; j++)
			{
				if(((MapTile*)world->getTile(i, j))->isCollidable())
				{
					canMove=false;
				}
			}
		}
		//si il n'a pas engendré de collision, alors on définit la nouvelle position 
		if(canMove)
			m_position = n_position;
		else //sinon on affine le déplacement
		{
			int dX = potential.x<0?1:-1,
				dY = potential.y<0?1:-1;
			potential.x+= dX;
			potential.y+= dY;
			topMin.x+=dX;
			topMin.y+=dY;
			bottomMax.x+=dX;
			bottomMax.y+=dY;
		}
	}
}

void LivingEntity::updateState(Controller *controller, sf::Time &elapsed, Tilemap *world)
{
	if(m_health>0) //si le joueur est encore en vie
	{
		Orientation n_orientation = m_orientation;
		sf::Vector2f potential;

		//on détermine une nouvelle orientation
		if(m_speed.y < 0)
			n_orientation = Orientation::TOP;
		else if(m_speed.y > 0)
			n_orientation = Orientation::BOTTOM;
		else if(m_speed.x > 0)
			n_orientation = Orientation::RIGHT;
		else if(m_speed.x < 0)
			n_orientation = Orientation::LEFT;

		//Si l'orientation a changé, alors on prend en compte son changement et on redémarre l'horloge qui contrôle le tick d'animation de mouvement
		if(m_orientation != n_orientation)
		{
			m_orientation = n_orientation;
			m_watcher.restart();
		}
	
		if(m_speed.x == 0 && m_speed.y == 0) //Si il est immobile alors le tick est à 0
			m_tick = 0;
		else if (m_watcher.getElapsedTime().asSeconds() > 0.75/SPEED_FACTOR) //Sinon on vérifie que l'horloge a dépassé l'intervalle requis pour changer de tick de mouvement
		{
			m_watcher.restart();
			m_tick = m_tick==1?2:1; //TODO généraliser pour x frames
		}

		//on définit le nouveau vecteur potentiel de position d'après la vitesse et le temps écoulé	
		potential.x = elapsed.asSeconds()*m_speed.x;
		potential.y = elapsed.asSeconds()*m_speed.y;
	
		//si le joueur bouge alors on le déplace
		if((potential.x != 0) or (potential.y != 0)) move(potential, world);
	}
}
	
void LivingEntity::draw(GameWindow* window)
{
	float offsetX = (m_tilesys->getTs()->getDisplayWidth()/(float)m_tilesys->getTs()->getWidth())*m_center.x;
	float offsetY = (m_tilesys->getTs()->getDisplayHeight()/(float)m_tilesys->getTs()->getHeight())*m_center.y;
	window->draw(*(m_tilesys->getTile(m_orientation)->getSprite(m_tick, m_position.x-offsetX, m_position.y-offsetY)));
}
