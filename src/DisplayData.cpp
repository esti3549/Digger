#include "DisplayData.h"

DisplayData::DisplayData()//c-tor
{
	m_printLives = sf::Text("LIVES:", Resources::getInstance().m_font);
	m_printStone = sf::Text("STONE:", Resources::getInstance().m_font);
	m_printScore = sf::Text("SCORE:", Resources::getInstance().m_font);
	m_printLevel = sf::Text("LEVEL:", Resources::getInstance().m_font);

	auto gray = sf::Color(47, 79, 79);

	setData(m_printLives, { 1050 , 150 }, 35, gray);
	setData(m_printStone, { 1050 , 270 }, 35, gray);
	setData(m_printScore, { 1050 , 390 }, 35, gray);
	setData(m_printLevel, { 1050 , 510 }, 35, gray);
}
//--------------------------------------------------------------------------------------------
void DisplayData::displayData(const int lives, const int stone, const int score, const int level, sf::RenderWindow& window, const int seconds)
{
	auto black = sf::Color::Black;
	displayTime(seconds, window);

	window.draw(m_printLives);
	auto text = sf::Text(std::to_string(lives), Resources::getInstance().m_font);
	setData(text, { m_printLives.getGlobalBounds().width / 2 + m_printLives.getPosition().x, 200 }, 40, black);
	window.draw(text);

	window.draw(m_printStone);
    text = sf::Text(std::to_string(stone), Resources::getInstance().m_font);
	setData(text, { m_printStone.getGlobalBounds().width / 2 + m_printStone.getPosition().x, 320 }, 40, black);
	window.draw(text);

	window.draw(m_printScore);
	text = sf::Text(std::to_string(score), Resources::getInstance().m_font);
	setData(text, { m_printScore.getGlobalBounds().width / 2 + m_printScore.getPosition().x, 440 }, 40, black);
	window.draw(text);

	window.draw(m_printLevel);
	text = sf::Text(std::to_string(level), Resources::getInstance().m_font);
	setData(text, { m_printLevel.getGlobalBounds().width / 2 + m_printLevel.getPosition().x, 560 }, 40, black);
	window.draw(text);
}
//---------------------------------------------------------------------------------------------------
void DisplayData::displayTime(const int seconds, sf::RenderWindow& window)
{
	auto text = sf::Text();
	auto color = sf::Color();
	
	if(seconds / 60 >= 10 && seconds % 60 >= 10)
		text = sf::Text(std::to_string(seconds / 60) + ":" + std::to_string(seconds % 60), Resources::getInstance().m_font);
	else if(seconds / 60 < 10 && seconds % 60 >= 10)
		text = sf::Text(std::to_string(0) + std::to_string(seconds / 60) + ":" + std::to_string(seconds % 60), Resources::getInstance().m_font);
	else if (seconds / 60 >= 10 && seconds % 60 < 10)
		text = sf::Text(std::to_string(seconds / 60) + ":" + std::to_string(0) + std::to_string(seconds % 60), Resources::getInstance().m_font);
	else
		text = sf::Text(std::to_string(0) + std::to_string(seconds / 60) + ":" + std::to_string(0) + std::to_string(seconds % 60), Resources::getInstance().m_font);

	if (seconds % 60 <= 30 && seconds / 60 < 1)//אם נשארה חצי דקה למשחק
		color = sf::Color::Red;
	else
		color = sf::Color::Black;
	setData(text, { 1040, 40 }, 55, color);
	window.draw(text);
}
//--------------------------------------------------------------------------------------------
void DisplayData::setData(sf::Text& text, sf::Vector2f position, int size, sf::Color color)
{
	text.setFillColor(color);
	text.setPosition(position);
	text.setCharacterSize(size);
}
