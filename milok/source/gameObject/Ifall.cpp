#include "Ifall.h"

Ifall::Ifall(Iplayer* playah)
{
	player = playah;
	timin = 0.0f;
}

void Ifall::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("fall"), 3,0.1);
	cu->setScale(3, 3);
	//cu->setPosition(0, 350);
}

void Ifall::Render(sf::RenderWindow* window)
{
	window->draw(*cu);

}

void Ifall::Update(float deltaTime)

{
	cu->Update(deltaTime);
	timin += deltaTime;
	player->getSkeleton()->move(0.5, 0.5*50*timin*timin);
	if (player->getSkeleton()->getPosition().y >= 400) {
		timin = 0.0f;
		player->changeState(RUN);
	}
	cu->setPosition(player->getSkeleton()->getPosition());

}

void Ifall::Reset()
{
	cu->Reset();
}
