#include "cobra.h"

void cobraCreep::Init()
{
	setStartPoint(sf::Vector2f(1000, 432));
	run = new animation(*resourceManage::GetInstance()->gtTexture("c"), 8, 0.09);
	death = new animation(*resourceManage::GetInstance()->gtTexture("deathcobra"), 8, 0.07);
	ske = new skeleton(sf::Vector2i(15, 21));
	death->setScale(4, 4);
	run->setScale(4, 4);
	ske->Init(sf::Vector2f(200, 200));
	ske->setPosition(sf::Vector2f(500, 432));
	ske->setTag(CREEP);
	ske->setAlive(1);
	current = run;
}
