#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
class Resources
{
public:
	std::vector<sf::Texture> m_imgs;//ווקטור של תמונות
	~Resources() = default;
	static Resources& getInstance();
	sf::Font m_font;
	sf::Music m_music;
	sf::Music m_failMusic;
	sf::Music m_winnerMusic;
protected:

	Resources();//c-tor
	Resources(const Resources& other) = default;//copy c-tor
	Resources& operator=(const Resources& other) = default;
	void pushImgToVector();//פונקצייה שמכניסה את התמונות לווקטור
};
