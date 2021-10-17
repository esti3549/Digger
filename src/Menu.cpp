#include "Menu.h"
#include <iostream>
//----------------------------------------------------------------------------------------
Menu::Menu():m_sprite(Resources::getInstance().m_imgs[menuPicture])//c-tor
{
	m_menu.push_back(new (std::nothrow)NewGameButton(startButton, sf::Vector2f(650, 550)));
	m_menu.push_back(new (std::nothrow)ExitButton(exitButton, sf::Vector2f(650, 630)));
}
//-------------------------------------------------------------------------------------
void Menu::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
		for (Button* button : m_menu)
			button->draw(window);
}
//-------------------------------------------------------------------------------------
void  Menu::handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window)
{
	for (Button* button : m_menu)
	{
		bool isButtonPressed = false;
		if (isContain(isButtonPressed,event,window,button))//אם הלחיצה הייתה על אחד הכפתורים
		{
			button->handleClick(event, window);
			if (isButtonPressed)
				return;
		}
	}
}
//----------------------------------------------------------------------------------------
void Menu::run(sf::RenderWindow& window)
{
	while (window.isOpen())
	{
		draw(window);//הצגת התפריט
		window.display();
		if (auto  event = sf::Event{}; window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				window.close();
				exit(0);
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				handleClick(event.mouseButton, window);
				return;
			}
			default:
				break;
			}
		}
	}
}
//-----------------------------------------------------------------------------------------
//אם הלחיצה מכילה את אחד הכפתורים
bool Menu::isContain(bool& isButtonPressed, const sf::Event::MouseButtonEvent& event,sf::RenderWindow& window, Button* button)
{
	if (button->getSprite().getGlobalBounds().contains(window.mapPixelToCoords({ event.x, event.y })))
	{
		isButtonPressed = true;
		return true;
	}
	return false;
}
