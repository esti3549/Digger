#include "StoneGift.h"

StoneGift::StoneGift(const Objects index,  sf::Vector2f location, int width, int hight)
	:Gift(index, location, width, hight)
{
}
//------------------------------------------------------------------------------------
Objects StoneGift::colide(Digger& digeer)
{
	digeer.addStonesForEating();
	return stoneGift;
}

void StoneGift::colide(Monster& monster)
{
}
