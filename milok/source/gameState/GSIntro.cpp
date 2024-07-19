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
	text.setFillColor(sf::Color::Red);
	text.setPosition(512-150, 350);
	sprite.setTexture(*resourceManage::GetInstance()->gtTexture("stool"));
	sprite.setPosition(512-50,256-100);
	sprite.setOrigin((sf::Vector2f) resourceManage::GetInstance()->gtTexture("cuc")->getSize() / 2.f);
	sprite.setScale(0.4, 0.4);
}

void GSIntro::Update(sf::Clock& cc)
{
	if (cc.getElapsedTime().asSeconds() > 1) {
		stateStack::GetInstance()->ChangeState(StateTypes::MENU);
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->clear(sf::Color::White);
	window->draw(sprite);
	window->draw(text);

}
