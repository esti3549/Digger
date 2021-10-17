#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Digger.h"

class ScoreGift : public Gift
{
public:
	ScoreGift(const Objects index,  sf::Vector2f location, int width, int hight);
	virtual ~ScoreGift () = default;
	virtual Objects colide(Digger& digeer) override;
	virtual void colide(Monster& monster) override;
protected:

};

