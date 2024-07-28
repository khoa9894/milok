#include "Bat.h"

void Bat::Init()
{
	setStartPoint(sf::Vector2f(1000, 200));
	run = new animation(*resourceManage::GetInstance()->gtTexture("FLYING"), 8, 0.09);
	death = new animation(*resourceManage::GetInstance()->gtTexture("deathBat"), 7, 0.09);
	ske = new skeleton(sf::Vector2i(24, 24));
	death->setScale(1.5, 1.5);
	run->setScale(1, 1);
	ske->Init(sf::Vector2f(100, 200));
	ske->setPosition(sf::Vector2f(1000, 200));
	current = run;
}
