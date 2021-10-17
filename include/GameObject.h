#pragma once
#include <SFML/Graphics.hpp>
#include "Const.h"
#include "Resources.h"
class GameObject
{
public:
	GameObject(const Objects index,  sf::Vector2f location, int width, int hight);
	~GameObject()= default;
	void setObject( sf::Vector2f location, int width, int hight);
	GameObject() = default;
	void draw(sf::RenderWindow& window);
protected:
	sf::Sprite m_sprite;
};
