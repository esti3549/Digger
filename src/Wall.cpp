#include "Wall.h"

Wall::Wall(const Objects index,  sf::Vector2f location, int width, int hight)
	:StaticObject(index, location, width, hight)
{
}

Objects Wall::colide(Digger& digeer)
{
	digeer.setPosition();
	return wall;
}

void Wall::colide(Monster& monster)
{
	monster.setDiarection({ 0,0 });//עצירה מלעלות על קיר

	monster.setPosition();
}
