#include "StaticObject.h"

StaticObject::StaticObject(const Objects index, sf::Vector2f location, int width, int hight)
	:GameObject(index,location,width,hight)
{
}
//----------------------------------------------------------------------------------------------
sf::FloatRect StaticObject::getRectangleSpriteSaticObject()
{
	return m_sprite.getGlobalBounds();
}

