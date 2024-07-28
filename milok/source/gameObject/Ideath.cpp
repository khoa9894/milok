#include "Ideath.h"

Ideath::Ideath(Iplayer* playah)
{
	player = playah;
}

void Ideath::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("death"), 11,0.1);
	cu->setScale(3, 3);
	cu->setPosition(0, 350);
}

void Ideath::Render(sf::RenderWindow* window)
{
	window->draw(*cu);

}

void Ideath::Update(float deltaTime)
{
	cu->Update(deltaTime);

}

void Ideath::Reset()
{
	cu->Reset();

}
