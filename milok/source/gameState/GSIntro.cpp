#include "GSIntro.h"

void GSIntro::Exit()
{
}

void GSIntro::Resume()
{
}

void GSIntro::Pause()
{
}

void GSIntro::Init()
{
	
	text.setFont(*resourceManage::GetInstance()->getFont("ARCADE_N"));
	text.setString("Du ma studio");
	text.setFillColor(sf::Color::Black);
	text.setPosition(300, 350);
	sprite.setTexture(*resourceManage::GetInstance()->gtTexture("cuc"));
	sprite.setPosition(971/2,497/2);
	sprite.setOrigin((sf::Vector2f) resourceManage::GetInstance()->gtTexture("cuc")->getSize() / 2.f);
	sprite.setScale(0.3, 0.3);
}

void GSIntro::Update(sf::Clock& cc)
{
	if (cc.getElapsedTime().asSeconds() > 0.1) {
		stateStack::GetInstance()->ChangeState(StateTypes::MENU);
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->clear(sf::Color::White);
	window->draw(sprite);
	window->draw(text);

}
