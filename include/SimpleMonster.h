#pragma once
#include <SFML/Graphics.hpp>
#include "Monster.h"

class SimpleMonster : public Monster
{
public:
	SimpleMonster (const Objects index, sf::Vector2f location, int width, int hight);
	virtual ~SimpleMonster () = default;
	virtual void move(sf::Time deltaTime) override;
	virtual void resetPosition() override;
protected:
	
};

