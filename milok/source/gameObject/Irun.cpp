#include "Irun.h"

Irun::Irun(Iplayer* playah)
{
	player = playah;
}

void Irun::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("run"),8);
	cu->setScale(3, 3);
	cu->setPosition(0, 350);

}

void Irun::Render(sf::RenderWindow* window)
{
	window->draw(*cu);
	
}

void Irun::Update(sf::Clock* cc)
{
	cu->Update(*cc);

}

void Irun::Reset()
{
	cu->Reset();
}
