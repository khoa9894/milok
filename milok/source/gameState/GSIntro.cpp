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
	fon.loadFromFile("../Data/Font/ARCADE_N.TTF");
	text.setFont(fon);
	text.setString("Du ma studio");
	text.setFillColor(sf::Color::Black);
	text.setPosition(300, 350);
	tex.loadFromFile("../Data/Textures/cuc.png");
	
	sprite.setTexture(tex);
	sprite.setPosition(971/2,497/2);
	
	sprite.setOrigin((sf::Vector2f)tex.getSize() / 2.f);
	sprite.setScale(0.3, 0.3);
}

void GSIntro::Update(sf::Clock& cc)
{
	if (cc.getElapsedTime().asSeconds() > 3) {
		stateStack::GetInstance()->ChangeState(StateTypes::MENU);
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->clear(sf::Color::White);
	window->draw(sprite);
	window->draw(text);

}
