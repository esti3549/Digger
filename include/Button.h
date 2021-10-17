#pragma once
#include <SFML/Graphics.hpp>
#include "Const.h"
#include "Resources.h"
class Button
{
public:
	Button(const Objects index,  sf::Vector2f location);
	virtual ~Button() = default;
	void draw(sf::RenderWindow& window);
	virtual void handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)=0;
	sf::Sprite getSprite();
protected:
	sf::Sprite m_sprite;

};

