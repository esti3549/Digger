#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Digger.h"

class StoneGift : public Gift
{
public:
	StoneGift(const Objects index,  sf::Vector2f location, int width, int hight);
	virtual ~StoneGift() = default;
	virtual Objects colide(Digger& digeer) override;
	virtual void colide(Monster& monster) override;

protected:

};

