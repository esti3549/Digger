#include "Controller.h"
#include <iostream>
//--------------------------------------------------------------------------------------
Controller::Controller():m_window(sf::VideoMode(WIDTH_OF_WINDOW, HEIGHT_OF_WINDOW), "Digger Game"),m_menu()
{
}
//--------------------------------------------------------------------------------------
void Controller::run()
{
	while (m_window.isOpen())
	{
		m_window.clear();//ניקוי החלון
		m_menu.run(m_window);
		Game game;
		game.run(m_window);
	}
}