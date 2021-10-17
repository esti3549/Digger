#include "ScoreGift.h"

ScoreGift::ScoreGift(const Objects index,  sf::Vector2f location, int width, int hight)
	:Gift(index, location, width, hight)
{
}

Objects ScoreGift::colide(Digger& digeer)
{
	digeer.setScore(10);
	return scoreGift;
}

void ScoreGift::colide(Monster& monster)
{
}
