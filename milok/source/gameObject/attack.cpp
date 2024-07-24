#include "attack.h"

Iattack::Iattack(Iplayer* playah)
{
	player = playah;

}

void Iattack::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("attack"), 10);
	cu->setScale(3, 3);
	//cu->setPosition(0, 350);
}

void Iattack::Render(sf::RenderWindow* window)
{
	window->draw(*cu);
}

void Iattack::Update(sf::Clock* cc)
{
	cu->Update(*cc);
	if (cc->getElapsedTime().asSeconds() > 0.1) {
		player->changeState(characterStateBase::characterState::RUN);
	}
	cu->setPosition(player->getSkeleton()->getPosition());
	
}

void Iattack::Reset()
{
	cu->Reset();

}
