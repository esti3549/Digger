#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Board.h"
#include "Monster.h"
#include "Digger.h"
#include "DisplayData.h"
class Level
{
public:
	Level(const std::string& levelFile);
   ~Level()= default;
	void  run(Digger& digger, sf::RenderWindow& window ,const std::string& levelFile,int& numOfLevel,bool& ifNextLevel, bool& ifGameOver);
	void setSimpleMonster(const Objects index,  sf::Vector2f location, int width, int hight);
	void setSmartMonster(const Objects index, sf::Vector2f location, int width, int hight, Digger& digger);
	void eventHandler(sf::RenderWindow& window, Digger& digger);
	sf::Time getDeltaTime();
	bool checkEof();
	void updateTime(float time);

protected:
	Board m_board;
	std::vector<Monster*> m_monsters;
	sf::Clock m_clock;
	sf::Clock m_timeLeft;
	DisplayData m_data;
	float m_clockOfLevel;
	void move(Digger& digger);
	void drawMonsters(sf::RenderWindow& window);
	void mainColision(Digger& digger);
	void diggerCollisionWithMonster(Digger& digger);//פןנקציה שמטפלת בהתנגשות שחקן עם מפלצת
	void diggerCollisionWithStaticObject(Digger& digger);//פונקציה שמטפלת בהתנגשות שחקן עם אובייקט כלשהוא
	void monsterCollisionWithStaticObject();//פונקציה שמטפלת בהתנגשות מפלצת עם אובייקט כלשהוא
};
