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
		digeer.setDiamondsForEating(-1);//����� ������ ������ �� �����
		digeer.setScore(15);//����� �� �����;
		return diamond;
	}
	else if (digeer.getDiamondsForEating() == 1)
	{
		digeer.setScore(35);//����� ����� �� �� ���� ���
		digeer.setDiamondsForEating(-1);//����� �� �����;
	}
}
//------------------------------------------------------------------------------
void Diamond::colide(Monster& monster)
{
}
