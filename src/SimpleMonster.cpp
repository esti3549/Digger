#include "SimpleMonster.h"
//------------------------------------------------------------------------------------------------
SimpleMonster::SimpleMonster(const Objects index, sf::Vector2f location, int width, int hight)
	:Monster(index,location,width,hight)
{
}
//--------------------------------------------------------------------------------------------------
void SimpleMonster::move(sf::Time deltaTime)
{
	int randDirection = rand() % 4;//הגרלת מספר
    m_NextDiarection = calculateDirection(Directions(randDirection));
	calculateRoad(m_NextDiarection, MONSTER_SPEED);
	if (checkLimit_1((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
	    	DinamicObject::move(deltaTime);
}
//------------------------------------------------------------------------------------------------
void SimpleMonster::resetPosition()
{
	m_sprite.setPosition(m_startingPosition);//החזרת מפלצת למקום ההתחלתי
}
//--------------------------------------------------------------------------

