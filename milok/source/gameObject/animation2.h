#pragma once

#include<SFML/Graphics.hpp>
class animation2 :public sf::Sprite
{
private:
	sf::Vector2i k_currentFrame;
	sf::Vector2i k_frameNum;
	sf::IntRect source;
	int numFrameX;
	double k_time;
	int numFrameY;
	double currentTime;

public:
	animation2(sf::Texture& tex, int numFrameX,int numFrameY, double tim);
	void calSize();
	void Update(float deltaTime);
	void Reset();
	//void setTime(double chuchu);
};

