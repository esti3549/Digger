#pragma once
#include <SFML/Graphics.hpp>
#include "StaticObject.h"

class Diamond : public StaticObject
{
public:
	Diamond (const Objects index,  sf::Vector2f location, int width, int hight);
   ~Diamond () = default;
	virtual Objects colide(Digger& digeer) override;
	virtual void colide(Monster& monster) override;
protected:

};

