#pragma once
#include<SFML/Graphics.hpp>
class animation :public sf::Sprite 
{
private:
	sf::Vector2i k_currentFrame;
	sf::Vector2i k_frameNum;
	sf::IntRect source;
	int k_numFrame;
	double k_time;
public:
	animation(sf::Texture &tex, int numFrame);
	void calSize();
	void Update(sf::Clock &cc);
	void Reset();
};

