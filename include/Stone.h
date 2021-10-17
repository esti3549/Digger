#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"
#include "Digger.h"

class Stone : public StaticObject
{
public:
	Stone (const Objects index,  sf::Vector2f location, int width, int hight);
	virtual ~Stone() = default;
	virtual Objects colide(Digger& digeer) override;
	virtual void colide(Monster& monster) override;
protected:

};

