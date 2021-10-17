#include "GameObject.h"
//-----------------------------------------------------------------------------------------------
GameObject::GameObject(const Objects index,  sf::Vector2f location, int width, int hight)
	        :m_sprite(Resources::getInstance().m_imgs[index])
{
	setObject(location, width, hight);
}
//---------------------------------------------------------------------------------------------------
void GameObject::setObject(sf::Vector2f location, int width, int hight)
{
	auto txt = m_sprite.getTexture();
	auto texSize = txt->getSize();
	auto newTexSize = sf::Vector2i(width, hight);
	auto scaleX = newTexSize.x * 1.00f / texSize.x;
	auto scaleY = newTexSize.y * 1.00f / texSize.y;
	m_sprite.setScale(scaleX, scaleY);
	m_sprite.setPosition(location);
}
//-----------------------------------------------------------------------------------------------------
void GameObject::draw(sf::RenderWindow& window)//ציור כל האוביקטים על המסך
{
	window.draw(m_sprite);
}
