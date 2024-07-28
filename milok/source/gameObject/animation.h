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
	double currentTime;
	int cobraX;
	int cobraY;
public:
	animation(sf::Texture &tex, int numFrame,double tim);
	void calSize();
	void Update(float deltaTime);
	void Reset();
	void setTime(double chuchu);
};

