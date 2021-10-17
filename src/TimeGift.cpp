#include "TimeGift.h"

TimeGift::TimeGift(const Objects index,  sf::Vector2f location, int width, int hight)
	:Gift(index, location, width, hight)
{
}
//-------------------------------------------------------------------------------
Objects TimeGift::colide(Digger& digger)
{
	digger.setTime(30);
	return timeGift;
}
//-------------------------------------------------------------------------------
void TimeGift::colide(Monster& monster)
{
}
