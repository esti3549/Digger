#include "Diamond.h"

Diamond::Diamond(const Objects index,  sf::Vector2f location, int width, int hight)
	:StaticObject(index,location,width,hight)
{
}
//--------------------------------------------------------------------------------
Objects Diamond::colide(Digger& digeer)
{
	if (digeer.getDiamondsForEating() != 1)
	{
		digeer.setDiamondsForEating(-1);//נפחית מהכמות שנשארה לו לאכול
		digeer.setScore(15);//נוסיף לו ניקוד;
		return diamond;
	}
	else if (digeer.getDiamondsForEating() == 1)
	{
		digeer.setScore(35);//תוספת ניקוד גם על מעבר שלב
		digeer.setDiamondsForEating(-1);//נוסיף לו ניקוד;
	}
}
//------------------------------------------------------------------------------
void Diamond::colide(Monster& monster)
{
}
