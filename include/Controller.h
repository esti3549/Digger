#pragma once
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Level.h"
#include "Menu.h"
#include "Resources.h"
#include "Game.h"
class Controller
{
public:
	Controller();
	~Controller() = default;
	void run();

protected:
	sf::RenderWindow m_window;
	Menu m_menu;
};
