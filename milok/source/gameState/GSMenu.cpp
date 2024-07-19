#include "GSMenu.h"
GSMenu::GSMenu() {

}
GSMenu::~GSMenu() {

}
void GSMenu::Exit()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Init()
{   //exit button
	
	gameButton* button;
	button = new gameButton();
	button->Init("close");
	button->setOrigin(button->getSize() / 2.f);
	button->setClick([]() {windowConector::GetInstance()->getWindow()->close(); });
	buttonList.push_back(button);
	button->setPosition(sf::Vector2f(971 / 2 + 250+50, 500 / 2 + 500 / 10 + 150 - 20));
	//Play button
	button = new gameButton();
	button->Init("play");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(sf::Vector2f(971 / 2+50, 500 / 2+500/10+60-40));
	button->setClick([]() {stateStack::GetInstance()->ChangeState(StateTypes::PLAY); });
	buttonList.push_back(button);
	//about
	button = new gameButton();
	button->Init("prize");
	button->setOrigin(button->getSize() / 2.f);
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(sf::Vector2f(971 / 2-100+50, 500 / 2 + 500 / 10 + 150-20));
	button->setClick([]() {stateStack::GetInstance()->ChangeState(StateTypes::HIGHSCORE); });
	buttonList.push_back(button);
	//highscore
	button = new gameButton();
	button->Init("about");
	button->setOrigin(button->getSize() / 2.f);
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(sf::Vector2f(971 / 2 - 250+50, 500 / 2 + 500 / 10 + 150 - 20));
	button->setClick([]() {stateStack::GetInstance()->ChangeState(StateTypes::ABOUT); });
	buttonList.push_back(button);
	//background
	button = new gameButton();
	button->Init("settings");
	button->setOrigin(button->getSize() / 2.f);
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(sf::Vector2f(971 / 2+100+50, 500 / 2 + 500 / 10 + 150-20));
	button->setClick([]() {stateStack::GetInstance()->ChangeState(StateTypes::SETTING); });
	buttonList.push_back(button);
	
	pi.setTexture(*resourceManage::GetInstance()->gtTexture("cucc"));
//	pi.setScale(2, 2);
	
	sf::Texture* tex = resourceManage::GetInstance()->gtTexture("idle");
	ani = new animation(*tex,6);
//	ani->setOrigin(sf::Vector2f(tex->getSize().x,tex->getSize().y));

	ani->setPosition(sf::Vector2f(971 / 2 + 50, 500 / 2 + 500 / 10 + 60 - 40-10));
	ani->setScale(5, 5);

}

void GSMenu::Update(sf::Clock& cc)
{
	for (auto it : buttonList) {
		it ->Update(cc);
	}
	ani->Update(cc);
}

void GSMenu::Render(sf::RenderWindow* window)
{
	
	window->draw(pi);
	for (auto it : buttonList) {
		it ->Render(window);
	}
	window->draw(*ani);
}
