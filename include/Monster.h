#pragma once
#include "DinamicObject.h"

class Monster : public DinamicObject
{
public:
	Monster (const Objects index, sf::Vector2f location, int width, int hight);
	virtual ~Monster () = default;
	virtual void move(sf::Time deltaTime) = 0;
	virtual void resetPosition() = 0;
	sf::FloatRect getRectangleOfSpriteMonster();
protected:

};

