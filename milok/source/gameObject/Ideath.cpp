#include "Ideath.h"

Ideath::Ideath(Iplayer* playah)
{
	player = playah;
	time = 0.0f;
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
	time += deltaTime;
	cu->Update(deltaTime);
	cu->setPosition(player->getSkeleton()->getPosition());
	if (time >= 1) {
		stateStack::GetInstance()->ChangeState(MENU);
	}
}

void Ideath::Reset()
{
	cu->Reset();

}
