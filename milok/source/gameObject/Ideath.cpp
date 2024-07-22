#include "Ideath.h"

Ideath::Ideath(Iplayer* playah)
{
	player = playah;
}

void Ideath::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("death"), 11);
	cu->setScale(3, 3);
	cu->setPosition(0, 350);
}

void Ideath::Render(sf::RenderWindow* window)
{
	window->draw(*cu);

}

void Ideath::Update(sf::Clock* cc)
{
	cu->Update(*cc);

}

void Ideath::Reset()
{
	cu->Reset();

}
