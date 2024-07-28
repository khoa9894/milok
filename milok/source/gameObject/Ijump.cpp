#include "Ijump.h"

Ijump::Ijump(Iplayer* playah)
{
	player = playah;
	timin = 0.0f;
}

void Ijump::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("jump"), 3,0.01);
	cu->setScale(3, 3);
//	cu->setPosition(0, 350);
}

void Ijump::Render(sf::RenderWindow* window)
{
	window->draw(*cu);
}

void Ijump::Update(float deltaTime)
{   
	
	timin += deltaTime;
	cu->Update(deltaTime);
	player->getSkeleton()->move(0, -((player->getSkeleton()->Velocity().y * timin) + (5 * timin * timin)));
	if (player->getSkeleton()->getPosition().y <=200) {
		player->changeState(FALL);
		timin = 0;
	}
	cu->setPosition(player->getSkeleton()->getPosition());
}

void Ijump::Reset()
{
	cu->Reset();
}
