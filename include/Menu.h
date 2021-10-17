#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "NewGameButton.h"
#include "ExitButton.h"
#include "Resources.h"
#include "Const.h"
class Menu
{
public:
	Menu();
	~Menu() = default;
	void draw(sf::RenderWindow& window);
	void  handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window);
	void run(sf::RenderWindow& window);
	
protected:
	std::vector< Button*> m_menu;
	sf::Sprite m_sprite;//מחזיק את תמונת הרקע של התפריט
	bool isContain(bool& isButtonPressed, const sf::Event::MouseButtonEvent& event, sf::RenderWindow& window,Button* button);
};

