#pragma once
#include "GameObject.h"
class Board;
class DinamicObject : public GameObject
{
public:
	DinamicObject (const Objects index,  sf::Vector2f location, int width, int hight);
	~DinamicObject() = default;
	DinamicObject() = default;
	void move(sf::Time deltaTime);
	bool checkLimit_1(sf::Vector2f location);
	void setPosition();
	void setPrevPosition();
	void setDiarection(sf::Vector2f diarection);
	sf::Vector2i getCell(Board& board);
	Directions getDirection();
protected:
	sf::Vector2f m_startingPosition;
	sf::Vector2f m_NextDiarection;//כיוון הבא
	sf::Vector2f m_positionDestination;//מיקום יעד
	sf::Vector2f m_direction;//כיוון נוכחי
	sf::Vector2f m_prevPosition;//מיקום קודם
	int corectPosition(int point, int num, int pointDiarection);
	sf::Vector2f calculateDirection(Directions index);
	void calculateRoad(sf::Vector2f& direction, int speed);
	void setPositionDestinationUpDown();
	void setPositionDestinationRightLeft();
};

