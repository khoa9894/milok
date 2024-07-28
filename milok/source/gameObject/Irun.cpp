#include "Irun.h"

Irun::Irun(Iplayer* playah)
{
	player = playah;
}

void Irun::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("run"),8,0.09);
	//cu = new animation(*resourceManage::GetInstance()->gtTexture("attack"), 10, 0.09);
	cu->setScale(3, 3);
//	cu->setPosition(0, 350);

}

void Irun::Render(sf::RenderWindow* window)
{
	window->draw(*cu);
	
}

void Irun::Update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
	
		player->getSkeleton()->move(player->getSkeleton()->Velocity().x * deltaTime, 0);
}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		player->getSkeleton()->move(-player->getSkeleton()->Velocity().x * deltaTime, 0);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player->changeState(characterStateBase::characterState::JUMP);
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player->changeState(characterStateBase::characterState::ATTACK);
	}
	cu->Update(deltaTime);
	cu->setPosition(player->getSkeleton()->getPosition());
}

void Irun::Reset()
{
	cu->Reset();
}
