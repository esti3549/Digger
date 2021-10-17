#include "Button.h"
//-------------------------------------------------------------------
Button::Button(const Objects index,  sf::Vector2f location) :m_sprite(Resources::getInstance().m_imgs[index])
{
	m_sprite.setPosition(location);
}
//----------------------------------------------------------------------
void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//------------------------------------------------------------------------
sf::Sprite Button::getSprite()
{
	return m_sprite;
}
