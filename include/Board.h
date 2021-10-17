#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "Const.h"
#include "StaticObject.h"
#include "Resources.h"
#include "Diamond.h"
#include "Wall.h"
#include "Stone.h"
#include "ScoreGift.h"
#include "StoneGift.h"
#include "TimeGift.h"
#include "Digger.h"
#include "SimpleMonster.h"
#include "SmartMonster.h"

class Level;
class Board
{
public:
	Board(const std::string& levelFile);//c-tor
	~Board();//d-tor
	void readFile(Level& level,Digger& digger1, const std::string& levelFile);//פונקצייה שקוראת מהקובץ
	void insertObjects(char c,int i,int j, int width, int hight,/* std::vector<Monster*>& monsters*/Level& level, Digger& digger1, int numOfStone);//עדכון הנתונים הנקראים מהקובץ
	void draw(sf::RenderWindow& window);//
	bool checkEof();
	bool isEmpty(sf::Vector2i cell);
	StaticObject* getCell(sf::Vector2i cell);
	void setCell(sf::Vector2i location);
protected:
	std::vector<std::vector<StaticObject*>> m_gameBoard;//המטריצה שמחזיקה אוביקטים סטטיים בהתאמה למה שמופיע בקובץ
	std::ifstream m_file;//קובץ לקריאה
	void openLevelFile(const std::string& levelFile);//פונקצייה שפותחת את הקובץ לקריאה
	int m_row;
	int m_col;
};

