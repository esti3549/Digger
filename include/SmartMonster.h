#pragma once
#include <SFML/Graphics.hpp>
#include "Monster.h"
#include "Digger.h"

class SmartMonster : public Monster
{
public:
	SmartMonster (const Objects index, sf::Vector2f location, int width, int hight, Digger& digger);
	virtual ~SmartMonster () = default;
	virtual void move(sf::Time deltaTime) override;
	sf::Vector2f getDiggerPosition();
	float manhattanÉDistance(sf::Vector2f possibleDestigntion);//ðåñçú îðäèï
	virtual void resetPosition() override;
protected:
	Digger& m_digger;
	void findMinDirection(sf::Time deltaTime);

};

