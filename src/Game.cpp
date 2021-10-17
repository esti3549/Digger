#include "Game.h"
#include <iostream>
//---------------------------------------------------------------------------
void Game::run(sf::RenderWindow& window)
{
	bool ifNextLevel, ifGameOver;
	auto filelevel = std::string("Level1.txt");
	int numOfLevel = 1;
	while (std::ifstream(filelevel))
	{
		ifNextLevel = false , ifGameOver = false;
		Level level(filelevel);
		level.run(m_digger, window, filelevel, numOfLevel, ifNextLevel, ifGameOver);
		
		if (ifNextLevel)//אם צריך לעבור שלב
			numOfLevel++;
		if (ifGameOver)//אם נגמר המשחק
		{
			Resources::getInstance().m_music.stop();
			Resources::getInstance().m_failMusic.play();
			resultGame(window, gameOver);
			break;
		}
		filelevel = std::string("Level") + std::to_string(numOfLevel) + std::string(".txt");
	}
	if (ifNextLevel) 
	{
		Resources::getInstance().m_music.stop();
		Resources::getInstance().m_winnerMusic.play();
		resultGame(window, winner);
	}
}
//---------------------------------------------------------------------------------------
//תוצאת המשחק האם ניצח או הפסיד והצגת תמונה ומוסיקה בהתאם
void Game::resultGame(sf::RenderWindow& window,Objects picture)
{
	window.clear(sf::Color::White);
	sf::Sprite sprite;
	sprite.setTexture(Resources::getInstance().m_imgs[picture]);
	window.draw(sprite);
	window.display();
	using namespace std::chrono_literals;
	std::this_thread::sleep_for(3s);

	Resources::getInstance().m_failMusic.stop();
	Resources::getInstance().m_winnerMusic.stop();

}
