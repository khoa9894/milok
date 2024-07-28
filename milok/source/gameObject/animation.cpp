 #include "animation.h"
#include <iostream>
using namespace std;
animation::animation(sf::Texture& tex, int numFrame,double tim)
{
	k_numFrame = numFrame;
	setTexture(tex);
	k_currentFrame = sf::Vector2i(0, 0);
	calSize();
	source = sf:: IntRect(k_currentFrame.x,k_currentFrame.y, k_frameNum.x, k_frameNum.y);
	setTextureRect(source);
	this->setOrigin((sf::Vector2f)k_frameNum/2.f);
	this->k_time = tim;
	currentTime = 0.0f;
	cobraX = tex.getSize().x;
	cobraY = tex.getSize().y;
}

void animation::calSize()
{
	k_frameNum.x = getTexture()->getSize().x / k_numFrame;
	k_frameNum.y = getTexture()->getSize().y;
}

void animation::Reset() {
	//cc.restart();
	source.left = 0;
}

void animation::Update(float deltaTime)
{
	currentTime += deltaTime;
	if (cobraX == 256) {
		if (currentTime > k_time) {
			if (source.left == 0) {
				source.left = cobraX - k_frameNum.x;
			}
			else {
				source.left -= k_frameNum.x;
				setTextureRect(source);
				currentTime -= k_time;
			}
		}
	}
	else {
		if (currentTime > k_time) {
			//printf("cho: %f\n", currentTime);
			if (source.left == cobraX - k_frameNum.x) {
				source.left = 0;
				// printf("%d\n", k_frameNum.x);
			}
			else {
				source.left += k_frameNum.x;
				setTextureRect(source);
				currentTime -= k_time;
			}
		}
	}
	
}
