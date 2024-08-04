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
	text.setString("Mai iu Milok");
	text.setFillColor(sf::Color::Red);
	text.setPosition(512-150, 350);
	sprite.setTexture(*resourceManage::GetInstance()->gtTexture("stool"));
	sprite.setPosition(512-50,256-100);
	sprite.setOrigin((sf::Vector2f) resourceManage::GetInstance()->gtTexture("cuc")->getSize() / 2.f);
	sprite.setScale(0.4f,0.4f);
	cur = 0.0f;
}

void GSIntro::Update(float deltaTime)
{
	 cur += deltaTime;
	// printf("cur: %f\n", cur);
	if (cur>=2) {
		stateStack::GetInstance()->ChangeState(StateTypes::MENU);
		cur = 0.0f;
	}
}

void GSIntro::Render(sf::RenderWindow* window)
{
	window->clear(sf::Color::White);
	window->draw(sprite);
	window->draw(text);

}
