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
	rec.setSize(sf::Vector2f (200, 200));
	rec.setFillColor(sf::Color::Red);
}

void GSIntro::Update(sf::Clock& cc)
{
	if (cc.getElapsedTime().asSeconds() > 1) {
		stateStack::GetInstance()->ChangeState(StateTypes::MENU);
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->draw(rec);
}
