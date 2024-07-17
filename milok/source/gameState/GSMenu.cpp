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
	button = new gameButtoun();
	button->Init();
	button->setClick([]() {windowConector::GetInstance()->getWindow()->close(); });
	buttonList.push_back(button);
	//Play button
	button = new gameButton();
	button->Init();
	button->setPosition(sf::Vector2f(300, 300));
	button->setFillColor(sf::Color::Magenta);
	button->setClick([]() {stateStack::GetInstance()->ChangeState(StateTypes::PLAY); });
	buttonList.push_back(button);
	//background
	
	text.loadFromFile("../Data/Backgrounds/background.png");
	pi.setTexture(text);
	//pi.setPosition((sf::Vector2f)text.getSize() / 2.f);

}

void GSMenu::Update(sf::Clock& cc)
{
	for (auto it : buttonList) {
		it ->Update(cc);
	}
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(pi);
	for (auto it : buttonList) {
		it ->Render(window);
	}
}
