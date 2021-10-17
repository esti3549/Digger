#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Gift : public StaticObject
{
public:
	Gift(const Objects index,  sf::Vector2f location, int width, int hight);
	virtual ~Gift() = default;
	virtual Objects colide(Digger& digeer) = 0;
	virtual void colide(Monster& monster) = 0;

protected:

};
