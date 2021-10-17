#include "SmartMonster.h"

SmartMonster::SmartMonster(const Objects index, sf::Vector2f location, int width, int hight, Digger& digger)
	:Monster(index, location,width,hight),m_digger(digger)
{
}
//---------------------------------------------------------------------------------------
void SmartMonster::move(sf::Time deltaTime)
{
	findMinDirection(deltaTime);
	if (checkLimit_1((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
	     DinamicObject::move(deltaTime);
}
//---------------------------------------------------------------------------------------
sf::Vector2f SmartMonster::getDiggerPosition()
{
	return m_digger.getDiggerPosition();
}
//----------------------------------------------------------------------------------------
float SmartMonster::manhattan�Distance(sf::Vector2f possibleDestigntion)//����� �����
{
	return (std::abs(possibleDestigntion.x - (m_digger.getDiggerPosition()).x) +
		    std::abs(possibleDestigntion.y - (m_digger.getDiggerPosition()).y));
}
//-----------------------------------------------------------------------------------------
void SmartMonster::resetPosition()
{
	m_sprite.setPosition(m_startingPosition);//����� ����� ����� �������
}
//-----------------------------------------------------------------------------------------
void SmartMonster::findMinDirection(sf::Time deltaTime)
{
	float distanseFromPlayer, minDistanseFromPlayer = 1250;
	int minDirection = 0;
	sf::Vector2f possibleDestination, direction;
	for (int i = 0; i < NUM_OF_DIRECTION; i++)
	{
		direction = calculateDirection(Directions(i));
		calculateRoad(direction, MONSTER_SPEED);
		possibleDestination = ((direction * (deltaTime.asSeconds())) + m_sprite.getPosition());
		distanseFromPlayer = manhattan�Distance(possibleDestination);
		if (distanseFromPlayer < minDistanseFromPlayer)
		{
			minDirection = i;
			minDistanseFromPlayer = distanseFromPlayer;
		}
	}
	m_NextDiarection= calculateDirection(Directions(minDirection));
	calculateRoad(m_NextDiarection, MONSTER_SPEED);	
}
