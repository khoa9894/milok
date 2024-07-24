 #include "animation.h"
#include <iostream>
using namespace std;
animation::animation(sf::Texture& tex, int numFrame)
{
	k_numFrame = numFrame;
	setTexture(tex);
	k_currentFrame = sf::Vector2i(0, 0);
	calSize();
	source = sf:: IntRect(k_currentFrame.x,k_currentFrame.y, k_frameNum.x, k_frameNum.y);
	setTextureRect(source);
	this->setOrigin((sf::Vector2f)k_frameNum/2.f);
	/*if (k_numFrame == 3) {
		k_time = 0.5;
	}
	else k_time = 0.1;*/
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
void animation::Update(sf::Clock &cc)
{
	if (cc.getElapsedTime().asSeconds() > 0.1) {
		if (source.left == getTexture()->getSize().x - k_frameNum.x) {
		 source.left = 0;
		}
		else {
			source.left += k_frameNum.x;
			setTextureRect(source);
			cc.restart();
		}
	}
}
