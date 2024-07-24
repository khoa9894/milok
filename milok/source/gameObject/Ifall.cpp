#include "Ifall.h"

Ifall::Ifall(Iplayer* playah)
{
	player = playah;
}

void Ifall::Init()
{
	cu = new animation(*resourceManage::GetInstance()->gtTexture("fall"), 3);
	cu->setScale(3, 3);
	//cu->setPosition(0, 350);
}

void Ifall::Render(sf::RenderWindow* window)
{
	window->draw(*cu);

}

void Ifall::Update(sf::Clock* cc)
{
	cu->Update(*cc);

	if (cc->getElapsedTime().asSeconds() > 0.1) {
		
		player->changeState(characterStateBase::characterState::RUN);
		
	}
	cu->setPosition(player->getSkeleton()->getPosition());

}

void Ifall::Reset()
{
	cu->Reset();
}
