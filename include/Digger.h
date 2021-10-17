#pragma once
#include <SFML/Graphics.hpp>
#include "DinamicObject.h"
#include "Const.h"

class Digger : public DinamicObject
{
public:
	Digger();
   ~Digger() = default;
	void setDigger(sf::Vector2f location, int width, int hight,int stone);
	void handleEvent(sf::Keyboard::Key key);
	void move(sf::Time deltaTime);
	sf::Vector2f getDiggerPosition();
	int getTime() const;
	int getLives() const;
	int getStone() const;
	int getScore() const;
	int getDiamondsForEating() const;
	void setDiamondsForEating(int num);
	void setScore(int score);
	void setTime(int time);
	bool checkStone();
	void setAllowedStone();
	void setLives();
	void addStonesForEating();
	sf::FloatRect getRectangleOfSpriteDigger() const;
	void resetPosition();
protected:
	int m_lives;//���� �����
	int m_stone;//���� ����� 
	int m_score;//�����
	int m_diamondsForEating ;//���� ������� ������ ������
	int m_time;//��� ������ ������
};

