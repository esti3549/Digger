#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Digger.h"

class TimeGift : public Gift
{
public:
	TimeGift(const Objects index,  sf::Vector2f location, int width, int hight);
	virtual ~TimeGift () = default;
	virtual Objects colide(Digger& digger) override;
	virtual void colide(Monster& monster) override;
protected:

};

