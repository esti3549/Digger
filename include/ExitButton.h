#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Const.h"

class ExitButton :public Button
{
public:
	ExitButton(const Objects index,  sf::Vector2f location);
	virtual ~ExitButton()= default;
	virtual void handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window) override;
protected:

};
