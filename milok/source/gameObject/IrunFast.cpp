#include "IrunFast.h"

IrunFast::IrunFast(Iplayer* playah)
{
	player = playah;
}

void IrunFast::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("run"), 8,0.1);
	cu->setScale(3, 3);
	//	cu->setPosition(0, 350);

}

void IrunFast::Render(sf::RenderWindow* window)
{
	window->draw(*cu);

}

void IrunFast::Update(float deltaTime)
{

	cu->Update(deltaTime);
	cu->setPosition(player->getSkeleton()->getPosition());
}

void IrunFast::Reset()
{
	cu->Reset();
}
