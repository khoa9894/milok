#include "attack.h"

Iattack::Iattack(Iplayer* playah)
{
	player = playah;

}

void Iattack::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("attack"), 10, 0.09);
	cu->setScale(3, 3);
	current = 0.0f;
	//cu->setPosition(0, 350);
}

void Iattack::Render(sf::RenderWindow* window)
{
	window->draw(*cu);
}

void Iattack::Update( float deltaTime)
{
	current += deltaTime;
	cu->Update(deltaTime);
	if (current > 0.8) {
		player->changeState(characterStateBase::characterState::RUN);
		current = 0.0f;
	}
	cu->setPosition(player->getSkeleton()->getPosition());
	
}

void Iattack::Reset()
{
	cu->Reset();

}
