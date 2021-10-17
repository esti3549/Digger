#include "Resources.h"
//------------------------------------------------------------------------
Resources& Resources::getInstance()
{
	static Resources m_instance;
	return m_instance;
}
//-------------------------------------------------------------------------
Resources::Resources()//c-tor
{
	pushImgToVector();
}
//-------------------------------------------------------------------------
void Resources::pushImgToVector()
{
	auto img = sf::Texture();
	img.loadFromFile("diamond.png");
	m_imgs.push_back(img);

	img.loadFromFile("digger.png");
	m_imgs.push_back(img);

	img.loadFromFile("exitButton.png");
	m_imgs.push_back(img);
	
	img.loadFromFile("gameBackGround.jpg");
	m_imgs.push_back(img); 

	img.loadFromFile("gameOver.png");
	m_imgs.push_back(img);

	img.loadFromFile("gray_stone.png");
	m_imgs.push_back(img);

	img.loadFromFile("menu_picture.jpg");
	m_imgs.push_back(img);

	img.loadFromFile("monster1.png");
	m_imgs.push_back(img);

	img.loadFromFile("monster2.png");
	m_imgs.push_back(img);

	img.loadFromFile("score_gift.png");
	m_imgs.push_back(img);

	img.loadFromFile("start.png");
	m_imgs.push_back(img);

	img.loadFromFile("stone_gift.PNG");
	m_imgs.push_back(img);

	img.loadFromFile("time_gift.PNG");
	m_imgs.push_back(img);

	img.loadFromFile("wall.jpg");
	m_imgs.push_back(img);

	img.loadFromFile("winner.png");
	m_imgs.push_back(img);

	m_font.loadFromFile("c:/Windows/Fonts/Forte.ttf");

	m_music.openFromFile("town.wav");
	m_failMusic.openFromFile("fail.wav");
	m_winnerMusic.openFromFile("clap.wav");
}
