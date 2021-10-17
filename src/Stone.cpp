#include "Stone.h"

Stone::Stone(const Objects index,  sf::Vector2f location, int width, int hight)
	:StaticObject(index,location,width,hight)
{
}
//----------------------------------------------------------------------------------
Objects Stone::colide(Digger& digeer)
{
	if (digeer.checkStone())//אם יש עוד אבנים לאכול
	{
		digeer.setAllowedStone();//נוריד אבנים
		return stone;
	}
	else
	{
		if (digeer.getLives() != 0)
			digeer.setLives();
		return stone;
		//אחרת gameOver
	}
	//return stone;
}

void Stone::colide(Monster& monster)
{
}
