#include "animation2.h"
#include <iostream>
animation2::animation2(sf::Texture& tex, int numFrameX, int numFrameY, double tim)
{
	this->numFrameX = numFrameX;
	this->numFrameY = numFrameY;
	setTexture(tex);
	k_currentFrame = sf::Vector2i(0, 0);
	calSize();
	source = sf::IntRect(k_currentFrame.x, k_currentFrame.y, k_frameNum.x, k_frameNum.y);
	setTextureRect(source);
	this->setOrigin((sf::Vector2f)k_frameNum / 2.f);
	this->k_time = tim;
	currentTime = 0.0f;
	
}

void animation2::calSize()
{
	k_frameNum.x = getTexture()->getSize().x /numFrameX;
	k_frameNum.y = getTexture()->getSize().y / numFrameY;
}

void animation2::Update(float deltaTime)
{
	currentTime += deltaTime;
	if (currentTime > k_time) {
		if (source.left == getTexture()->getSize().x - 2*k_frameNum.x && source.top == getTexture()->getSize().y - k_frameNum.y) {
			source.left = 0;
			source.top = 0;
			
		}
	    if (source.left == getTexture()->getSize().x- k_frameNum.x) {
				source.left = 0;
				source.top += k_frameNum.y;
			}
			source.left += k_frameNum.x;
			setTextureRect(source);
			currentTime -= k_time;
	}
}

void animation2::Reset()
{
	source.left = 0;
}


