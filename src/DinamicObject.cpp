#include "DinamicObject.h"
#include "Board.h"
#include <iostream>

DinamicObject::DinamicObject(const Objects index,  sf::Vector2f location, int width, int hight)
	:GameObject(index, location, width, hight),m_startingPosition(location)
{
}
//------------------------------------------------------------------------------
void DinamicObject::move(sf::Time deltaTime)//תזוזה לפי צירים 
{
	if (std::abs(m_sprite.getPosition().x - m_positionDestination.x) <= EPSILON &&
		std::abs(m_sprite.getPosition().y - m_positionDestination.y) <= EPSILON)
	{
		m_direction = m_NextDiarection;
		if (checkLimit_1((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
		     m_sprite.move(m_direction * deltaTime.asSeconds());
	}
	if (checkLimit_1((m_direction * deltaTime.asSeconds()) + m_sprite.getPosition()))
	   m_sprite.move(m_direction * deltaTime.asSeconds());
}
//---------------------------------------------------------------------------------
bool DinamicObject::checkLimit_1(sf::Vector2f location)//בדיקה אם אין חריגה מגבולות הלוח
{
	return(location.x >= 0 && location.x + m_sprite.getGlobalBounds().width <= WIDTH_OF_BOARD &&
		   location.y >= 0 && location.y + m_sprite.getGlobalBounds().height <= HEIGHT_OF_WINDOW);
}
//------------------------------------------------------------------------------
void DinamicObject::setPosition()//שינוי מיקום נוכחי למיקום המתאים לפי הצירים
{
	if (m_direction.x > 0)
		m_positionDestination.x = m_positionDestination.x - m_sprite.getGlobalBounds().width;
	if (m_direction.y > 0)
		m_positionDestination.y = m_positionDestination.y - m_sprite.getGlobalBounds().height;
	m_sprite.setPosition(sf::Vector2f(ceil(m_prevPosition.x), ceil(m_prevPosition.y)));
}
//------------------------------------------------------------------------------
void DinamicObject::setPrevPosition()//שמירת המיקום הראשוני לפני שמתבצעת תזוזה
{
	m_prevPosition = m_sprite.getPosition();
}
//----------------------------------------------------------------------------
void DinamicObject::setDiarection(sf::Vector2f diarection)
{
	m_direction = diarection;
}
//------------------------------------------------------------------------------
sf::Vector2i DinamicObject::getCell(Board& board)//מחזירה את התא שהשחקן מתנגש בו לפי כיוון השחקן
{
	auto cell = sf::Vector2i(-1, -1);
	auto width = m_sprite.getGlobalBounds().width;
	auto height = m_sprite.getGlobalBounds().height;
	auto x = m_sprite.getPosition().x;
	auto y = m_sprite.getPosition().y;
	switch (getDirection())
	{
	case Up:
		cell = sf::Vector2i(floor((x+4) / width), floor((y+4) / height));
		break;
	case Down:
		cell = sf::Vector2i(floor((x+4) / width), floor((y + height-4) / height));
		break;
	case Right:
		cell = sf::Vector2i(floor((x + width-4) / width), floor((y+4) / height));
		break;
	case Left:
		cell = sf::Vector2i(floor((x+4) / width), floor((y+4) / height));
		break;
	default:
		break;
	}
	if (cell != sf::Vector2i(-1, -1))
	{
		if (!board.isEmpty(cell))
			return cell;
	}
	return cell = sf::Vector2i(-1, -1);//במקרה של null  או במקרה של עצירה
}
//---------------------------------------------------------------------
Directions DinamicObject::getDirection()//מחזירה את הכיוון
{
	if (m_direction.x == 0 && m_direction.y == 0)
		return Default;
	else if (m_direction.x < 0)
		return Left;
	else if (m_direction.x > 0)
		return Right;
	else if (m_direction.y < 0)
		return Up;
	else if (m_direction.y > 0)
		return Down;
}
//------------------------------------------------------------------
int DinamicObject::corectPosition(int point, int num, int pointDiarection)//מחזירה את המיקום הנכון שאליו צריך להגיע לפי הצירים
{
	point =(point - (point % num));//חישוב נקודת הצירים  
	if (pointDiarection > 0)//כלומר אם הכוון ימינה או למטה
		return point + num + EPSILON;//מוסיפה כדי לקדם אותו
	//אחרת זה אומר שהוא במיקום כבר 
	return point;
}
//-------------------------------------------------------------------------------
sf::Vector2f DinamicObject::calculateDirection(Directions index)//חישוב הכיוון לפי הקלט של המשתמש מהמקלדת
{
	sf::Vector2f direction;
	switch (index)
	{
	case Up:
		setPositionDestinationUpDown();
		return direction = { 0 , -1 };
	case Down:
		setPositionDestinationUpDown();
		return direction = { 0 , 1 };
	case Left:
		setPositionDestinationRightLeft();
		return direction = { -1 , 0 };
	case Right:
		setPositionDestinationRightLeft();
		return direction = { 1 , 0 };
	default:
		break;
	}
}
//--------------------------------------------------------------------
void DinamicObject::calculateRoad(sf::Vector2f& direction, int speed)//חישוב דרך 
{
	direction.x *= speed;
	direction.y *= speed;
}
//--------------------------------------------------------------------
void DinamicObject::setPositionDestinationUpDown()
{
	m_positionDestination.x = corectPosition(floor(m_sprite.getPosition().x), (m_sprite.getGlobalBounds().width), m_direction.x);
	m_positionDestination.y = m_sprite.getPosition().y;
}
//---------------------------------------------------------------------
void DinamicObject::setPositionDestinationRightLeft()
{
	m_positionDestination.y = corectPosition(floor(m_sprite.getPosition().y), (m_sprite.getGlobalBounds().height), m_direction.y);
	m_positionDestination.x = m_sprite.getPosition().x;
}


