#pragma once
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Digger.h"
#include <iostream>
#include <chrono>
#include <thread>
class Game
{
public:
	Game() =default;
   ~Game() = default;
   void run(sf::RenderWindow& window);
protected:
	void resultGame(sf::RenderWindow& window,Objects picture);
	Digger m_digger;
};

