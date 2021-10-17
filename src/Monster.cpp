#include "Monster.h"

Monster::Monster(const Objects index, sf::Vector2f location, int width, int hight)
	:DinamicObject(index, location, width, hight)
{
}
//-----------------------------------------------------------------------------------
sf::FloatRect Monster::getRectangleOfSpriteMonster()
{
	return m_sprite.getGlobalBounds();
}



