#pragma once
#include "GameObject.h"
#include "Digger.h"
#include "Monster.h"
class StaticObject : public GameObject
{
public:
	StaticObject(const Objects index, sf::Vector2f location, int width, int hight);
	virtual ~StaticObject() = default;
	virtual Objects colide(Digger& digeer) = 0;
	virtual void colide(Monster& monster) = 0;
	sf::FloatRect getRectangleSpriteSaticObject();
protected:

};
