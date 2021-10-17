#pragma once
#include <SFML/Graphics.hpp>
#include "Const.h"
#include "Resources.h"
class DisplayData
{
public:
	DisplayData();
	~DisplayData() = default;
	void displayData(const int lives, const int stone, const int score, const int level,
		             sf::RenderWindow& window, const int seconds);//������� ����� ������ ����

protected:
	sf::Text m_printLives;
	sf::Text m_printStone;
	sf::Text m_printScore;
	sf::Text m_printLevel;
	void displayTime(const int seconds, sf::RenderWindow& window);//������� ������ �� ����� ���� �� ����
	void setData(sf::Text& text,sf::Vector2f position,int size,sf::Color color);
};

