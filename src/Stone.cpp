#include "Stone.h"

Stone::Stone(const Objects index,  sf::Vector2f location, int width, int hight)
	:StaticObject(index,location,width,hight)
{
}
//----------------------------------------------------------------------------------
Objects Stone::colide(Digger& digeer)
{
	if (digeer.checkStone())//�� �� ��� ����� �����
	{
		digeer.setAllowedStone();//����� �����
		return stone;
	}
	else
	{
		if (digeer.getLives() != 0)
			digeer.setLives();
		return stone;
		//���� gameOver
	}
	//return stone;
}

void Stone::colide(Monster& monster)
{
}
