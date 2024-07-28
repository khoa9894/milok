#include "GSHighScore.h"

GSHighScore::GSHighScore()
{
}

GSHighScore::~GSHighScore()
{
}

void GSHighScore::Exit()
{
}

void GSHighScore::Resume()
{
}

void GSHighScore::Pause()
{
}

void GSHighScore::Init()
{
	pi.setTexture(*resourceManage::GetInstance()->gtTexture("cucc"));
	butt = new gameButton();
	butt->Init("close");
	butt->setOrigin(butt->getSize() / 2.f);
	butt->setPosition(sf::Vector2f(850, 70));
	butt->setClick([]() {stateStack::GetInstance()->PopState(); });
}

void GSHighScore::Update(float deltaTime)
{
	butt->Update(deltaTime);
}

void GSHighScore::Render(sf::RenderWindow* window)
{
	window->draw(pi);
	butt->Render(window);
}
