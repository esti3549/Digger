#include "Digger.h"
#include <iostream>
Digger::Digger():m_lives(TOTAL_LIVE), m_stone(0),m_score(0), m_diamondsForEating(0), m_time(0)
{
	m_sprite.setTexture(Resources::getInstance().m_imgs[digger]);
}
//------------------------------------------------------------------------------------------------
void Digger::setDigger( sf::Vector2f location, int width, int hight,int stone)
{
	setObject(location, width, hight);
	m_stone=stone;
	m_startingPosition = location;
}
//-------------------------------------------------------------------------------------------------
void Digger::handleEvent(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Up:
		m_NextDiarection = calculateDirection(Directions(key - 71));
		calculateRoad(m_NextDiarection, DIGGER_SPEED);
		break;
	case sf::Keyboard::Down:
		m_NextDiarection = calculateDirection(Directions(key - 71));
		calculateRoad(m_NextDiarection, DIGGER_SPEED);
		break;
	case sf::Keyboard::Left:
		m_NextDiarection = calculateDirection(Directions(key - 71));
		calculateRoad(m_NextDiarection, DIGGER_SPEED);
		break;
	case sf::Keyboard::Right:
		m_NextDiarection = calculateDirection(Directions(key - 71));
		calculateRoad(m_NextDiarection, DIGGER_SPEED);
		break;
	case sf::Keyboard::Space:
		if (m_direction.x != 0)
			setPositionDestinationUpDown();
		if (m_direction.y != 0)
			setPositionDestinationRightLeft();
		m_NextDiarection = { 0, 0 };
		break;
	default:
		break;
	}
}
//-------------------------------------------------------------------------------
void Digger::move(sf::Time deltaTime)
{
	if (checkLimit_1((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
		DinamicObject::move(deltaTime);
}
//--------------------------------------------------------------------------------
sf::Vector2f Digger::getDiggerPosition()
{
	return m_sprite.getPosition();
}
//-------------------------------------------------------------------------------
int Digger::getTime() const
{
	return m_time;
}
//--------------------------------------------------------------------------------
int Digger::getLives() const
{
	return m_lives;
}
//---------------------------------------------------------------------------------
int Digger::getStone() const
{
	return m_stone;
}
//---------------------------------------------------------------------------------
int Digger::getScore() const
{
	return m_score;
}
//------------------------------------------------------------------------------------
int Digger::getDiamondsForEating() const
{
	return m_diamondsForEating;
}
//---------------------------------------------------------------------------------------
void Digger::setDiamondsForEating(int num)
{
	m_diamondsForEating += num;
}
//---------------------------------------------------------------------------------------
void Digger::setScore(int score)
{
	m_score += score;
}
//------------------------------------------------------------------------------------
void Digger::setTime(int time)
{
	m_time += time;
}
//------------------------------------------------------------------------------------
bool Digger::checkStone()
{
	if (m_stone != 0)
		return true;
	return false;
}
//------------------------------------------------------------------------------------
void Digger::setAllowedStone()
{
	m_stone--;
}
//------------------------------------------------------------------------------------
void Digger::setLives()
{
	m_lives--;
}
//------------------------------------------------------------------------------------
void Digger::addStonesForEating()
{
	m_stone += 2;
}
//-----------------------------------------------------------------------------------
sf::FloatRect Digger::getRectangleOfSpriteDigger() const
{
	return m_sprite.getGlobalBounds();
}
//----------------------------------------------------------------------------------
void Digger::resetPosition()
{
	m_sprite.setPosition(m_startingPosition);
}
//---------------------------------------------------------------------------------


