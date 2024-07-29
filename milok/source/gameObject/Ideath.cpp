#include "Ideath.h"

Ideath::Ideath(Iplayer* playah)
{
	player = playah;
}

void Ideath::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("death"), 11,0.1);
	cu->setScale(3, 3);

}

void Ideath::Render(sf::RenderWindow* window)
{
	window->draw(*cu);

}

void Ideath::Update(float deltaTime)
{
	cu->Update(deltaTime);
	cu->setPosition(player->getSkeleton()->getPosition());
}

void Ideath::Reset()
{
	cu->Reset();

}
