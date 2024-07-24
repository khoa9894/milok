#include "Ijump.h"

Ijump::Ijump(Iplayer* playah)
{
	player = playah;
}

void Ijump::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("jump"), 3);
	cu->setScale(3, 3);
//	cu->setPosition(0, 350);
}

void Ijump::Render(sf::RenderWindow* window)
{
	window->draw(*cu);
}

void Ijump::Update(sf::Clock* cc)
{
	cu->Update(*cc);
	if (cc->getElapsedTime().asSeconds()>0.1) {
		player->changeState(characterStateBase::characterState::FALL);
	}
	cu->setPosition(player->getSkeleton()->getPosition());
}

void Ijump::Reset()
{
	cu->Reset();
}
