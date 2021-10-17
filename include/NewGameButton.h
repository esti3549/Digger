#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Const.h"
class NewGameButton : public Button
{
public:
	NewGameButton(const Objects index,  sf::Vector2f location);
	virtual ~NewGameButton()= default;
	virtual void handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window) override;

protected:

};

