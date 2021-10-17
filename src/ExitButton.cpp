#include "ExitButton.h"
#include <iostream>

ExitButton::ExitButton(const Objects index,  sf::Vector2f location)
	:Button(index,location)
{
}
//-----------------------------------------------------------------------------------------------------
void ExitButton::handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	window.close();
	exit(0);
}
