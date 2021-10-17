#include "Board.h"
#include <iostream>
#include "Level.h"
//-------------------------------------------------------------------------------
Board::Board(const std::string& levelFile)//c-tor
{
	openLevelFile(levelFile);//פתיחת קובץ לקריאה
}
//------------------------------------------------------------------------------
Board::~Board()//d-tor
{
	for (int i = 0; i < m_col; i++)
		for (int j = 0; j < m_row; j++)
			delete m_gameBoard[i][j];
		       m_file.close();
}
//--------------------------------------------------------------------------------
//קריאת הנתונים מהקובץ
void Board::readFile(Level& level, Digger& digger1, const std::string& levelFile)
{
	int row, col, numOfStones, timer;
	m_file >> row >> col >> numOfStones >> timer;
	
	level.updateTime(timer);
	int width = floor(WIDTH_OF_BOARD / col);//חישוב רוחב כל תא
	int hight = floor(HEIGHT_OF_WINDOW / row);//חישוב גובה כל תא
	m_row = row;
	m_col = col;
	m_gameBoard.resize(row);
	char c = m_file.get();
	srand(time(0));//אתחול
	//לולאה שעוברת על הקובץ קוראת ומעדכנת נתונים 
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			c = m_file.get();
			insertObjects(c, i, j, width, hight,  level, digger1,numOfStones);
		}
		c = m_file.get();
	}
}
//---------------------------------------------------------------------------
void Board::insertObjects(char c, int i, int j, int width, int hight, Level& level, Digger& digger1,int numOfStone)
{
	sf::Vector2f location(j * width, i * hight);//חישוב פינה שמאלית עליונה
	switch (c)
	{
	case DIAMOND://אם התו הוא יהלום
	{
		digger1.setDiamondsForEating(1);
		m_gameBoard[i].push_back(new (std::nothrow)Diamond(diamond, location, width, hight));
		break;
	}
	case WALL: //אם התו הוא קיר
	{
		m_gameBoard[i].push_back(new (std::nothrow)Wall(wall, location, width, hight));
		break;
	}
	case STONE://אם התו הוא אבן
	{
		m_gameBoard[i].push_back(new (std::nothrow)Stone(stone, location, width, hight));
		break;
	}
	case GIFT://אם התו הוא מתנה
	{
		int typeOfGift = rand() % 3; //מגריל מספר רנדומלי בין 0 ל2
		if (typeOfGift == 0)
			m_gameBoard[i].push_back(new (std::nothrow)ScoreGift(scoreGift, location, width, hight));
		if (typeOfGift == 1)
			m_gameBoard[i].push_back(new (std::nothrow)StoneGift(stoneGift, location, width, hight));
		if (typeOfGift == 2)
			m_gameBoard[i].push_back(new (std::nothrow)TimeGift(timeGift, location, width, hight));
		break;
	}
	case DIGGER://אם התו הוא שחקן
	{
		digger1.setDigger(location, width, hight,numOfStone);
		m_gameBoard[i].push_back(nullptr);
		break;
	}
	case MONSTER://אם התו הוא מפלצת
	{
		int typeOfMonster = rand() % 2;//מגריל מספר רנדומלי בין 0 ל1
		if (typeOfMonster == 0)
		   level.setSimpleMonster(monster2, location, width, hight);//
		else
			level.setSmartMonster(monster1, location, width, hight, digger1);//
		m_gameBoard[i].push_back(nullptr);
		break;
	}
	case SPACE:
	{
		m_gameBoard[i].push_back(nullptr);
	}
	default:
		break;
	}
}
//---------------------------------------------------------------------------
void Board::draw(sf::RenderWindow& window)
{
        window.clear(sf::Color(255 ,222 ,173));//back ground color
		sf::Sprite sprite(Resources::getInstance().m_imgs[gameBackGround]);
		window.draw(sprite);
		for (int i = 0; i < m_gameBoard.size(); i++)
			for (int j = 0; j < m_gameBoard[i].size(); j++)
				if(m_gameBoard[i][j]!=nullptr)
			    	m_gameBoard[i][j]->draw(window);
}
//-------------------------------------------------------------------------
bool Board::checkEof()
{
	return !m_file.eof();
}
//-------------------------------------------------------------------------
bool Board::isEmpty(sf::Vector2i cell)
{
	if (m_gameBoard[cell.y][cell.x] == nullptr || cell.y >= m_row || cell.x >= m_col)
		return true;
	return false;
}
//----------------------------------------------------------------------------
StaticObject* Board::getCell(sf::Vector2i cell)
{
	    return m_gameBoard[cell.y][cell.x];
}
//-----------------------------------------------------------------------------
void Board::setCell(sf::Vector2i location)
{
	m_gameBoard[location.y][location.x] = nullptr;
	delete m_gameBoard[location.y][location.x];
}
//--------------------------------------------------------------------------
void Board::openLevelFile(const std::string& levelFile)
{
	m_file.open(levelFile);
	if (!m_file.is_open())
	{
		std::cerr << "Can't open the file \n";
		exit(EXIT_FAILURE);
	}
}

