#include "Irun.h"

Irun::Irun(Iplayer* playah)
{
	player = playah;
}

void Irun::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("run"),8);
	cu->setScale(3, 3);
//	cu->setPosition(0, 350);

}

void Irun::Render(sf::RenderWindow* window)
{
	window->draw(*cu);
	
}

void Irun::Update(sf::Clock* cc)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		player->getSkeleton()->move(player->getSkeleton()->Velocity().x * 0.1, 0);
}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player->changeState(characterStateBase::characterState::JUMP);

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player->changeState(characterStateBase::characterState::ATTACK);
	}
	cu->Update(*cc);
	cu->setPosition(player->getSkeleton()->getPosition());
}

void Irun::Reset()
{
	cu->Reset();
}
