#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "Digger.h"
class Wall : public StaticObject
{
public:
	Wall(const Objects index,  sf::Vector2f location, int width, int hight);
	virtual ~Wall()= default;
	virtual Objects colide(Digger& digeer)override;
	virtual void colide(Monster& monster) override;
protected:

};

