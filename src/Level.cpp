#include "Level.h"
#include <iostream>
//-----------------------------------------------------------------------------------------------
Level::Level(const std::string& levelFile):m_board(levelFile),m_clock(), m_data()
{
	Resources::getInstance().m_music.play();
}
//----------------------------------------------------------------------------------------------
void  Level::run(Digger& digger, sf::RenderWindow& window, const std::string& levelFile, int& numOfLevel, bool& ifNextLevel, bool& ifGameOver)
{
	m_board.readFile(*this, digger,levelFile);//קריאת השלב
	while ((digger.getLives() > 0 && digger.getDiamondsForEating() >= 0 &&
		   int(m_clockOfLevel-(m_timeLeft.getElapsedTime().asSeconds()) + digger.getTime() >= 0)))
	{
	   window.clear();
	   m_board.draw(window);
	   m_data.displayData(digger.getLives(), digger.getStone(), digger.getScore(), numOfLevel,
		                  window, m_clockOfLevel -  m_timeLeft.getElapsedTime().asSeconds() + digger.getTime());//תצוגת מידע
	   drawMonsters(window);
	   digger.draw(window);
	   window.display();
	   eventHandler(window, digger);
	   digger.setPrevPosition();
	   move(digger);
	   mainColision(digger);//התנגשויות
	   if (digger.getDiamondsForEating() == 0)
	   {
		   ifNextLevel = true;
		   return;
	   }
	   else if (int(m_clockOfLevel - (m_timeLeft.getElapsedTime().asSeconds()) + digger.getTime() < 0))
	   {
		   ifNextLevel = false;
		   return;
	   }
	   else if (digger.getLives() == 0)
	   {
		   ifGameOver = true;
		   return;
	   }
	}
}
//-----------------------------------------------------------------------------------------------
void Level::setSimpleMonster(const Objects index, sf::Vector2f location, int width, int hight)
{
	m_monsters.push_back(new(std::nothrow)SimpleMonster(index, location, width, hight));
}
//------------------------------------------------------------------------------------------------
void Level::setSmartMonster(const Objects index, sf::Vector2f location, int width, int hight,Digger& digger)
{
	m_monsters.push_back(new(std::nothrow)SmartMonster(index, location, width, hight, digger));
}
//-------------------------------------------------------------------------------------------------
void Level::drawMonsters(sf::RenderWindow& window)
{
	for (Monster* mon : m_monsters)
		mon->draw(window);
}
//------------------------------------------------------------------------------------------------
void Level::eventHandler(sf::RenderWindow& window,Digger& digger)
{
	auto event = sf::Event{};
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			exit(0);
			break;
		case sf::Event::KeyPressed:
		{
			digger.handleEvent(event.key.code);
			digger.move(getDeltaTime());
			break;
		}
		default:
			break;
		}
	}
}
//---------------------------------------------------------------------------------
sf::Time Level::getDeltaTime()
{
	auto deltaTime = m_clock.restart();
	return deltaTime;
}
//--------------------------------------------------------------------------------------
bool Level::checkEof()
{
	return m_board.checkEof();
}
//---------------------------------------------------------------------------------------
void Level::updateTime(float time)
{
	m_clockOfLevel = time;
}
//----------------------------------------------------------------------------------------
void Level::mainColision(Digger& digger)
{
	//התנגשות שחקן עם מפלצת
	diggerCollisionWithMonster(digger);
	//התנגשות שחקן עם אחד האובייקטים
	diggerCollisionWithStaticObject(digger);
	//התנגשות מפלצת עם אחד האוביקטים
	monsterCollisionWithStaticObject();
}
//------------------------------------------------------------------------------------------
void Level::diggerCollisionWithMonster(Digger& digger)
{
	for (auto mon : m_monsters)
	{
		if (digger.getRectangleOfSpriteDigger().intersects(mon->getRectangleOfSpriteMonster()))//בדיקה אם יש התנגשות
		{
			if (digger.getLives() != 0)//בדיקה אם נשאר חיים
			{
				digger.setLives();//נוריד חיים לשחקן
				digger.resetPosition();//נחזיר את השחקן למיקום ההתחלתי
				for (auto mon : m_monsters)//נחזיר מפלצות למיקום ההתחלתי
					mon->resetPosition();
			}
		}
	}
}
//--------------------------------------------------------------------------------------
void Level::diggerCollisionWithStaticObject(Digger& digger)
{
	auto cell = sf::Vector2i();
	cell = digger.getCell(m_board);
	if (cell != sf::Vector2i(-1, -1))
	{
		if (m_board.getCell(cell)->colide(digger) != wall)
			m_board.setCell(cell);//מחיקת התמונה
	}
}
//--------------------------------------------------------------------------------------
void Level::monsterCollisionWithStaticObject()
{
	auto cell = sf::Vector2i();
	for (auto mon : m_monsters)
	{
		cell = mon->getCell(m_board);
		if (cell != sf::Vector2i(-1, -1))
		{
			m_board.getCell(cell)->colide(*mon);
		}
	}
}
//----------------------------------------------------------------------------------------
void Level::move(Digger& digger)
{
	digger.move(m_clock.getElapsedTime());

	srand(time(0));//אתחול
	auto deltaTime = getDeltaTime();
	for (Monster* mon : m_monsters)
	{
		mon->setPrevPosition();
		mon->move(deltaTime);
	}
}
