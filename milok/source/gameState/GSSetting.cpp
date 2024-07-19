#include "GSSetting.h"

GSSetting::GSSetting()
{
}

GSSetting::~GSSetting()
{
}

void GSSetting::Exit()
{
}

void GSSetting::Resume()
{
}

void GSSetting::Pause()
{
}

void GSSetting::Init()
{
	pi.setTexture(*resourceManage::GetInstance()->gtTexture("cucc"));
	butt = new gameButton();
	butt->Init("close");
	butt->setOrigin(butt->getSize() / 2.f);
	butt->setPosition(sf::Vector2f(850, 70));
	butt->setClick([]() {stateStack::GetInstance()->PopState(); });
}

void GSSetting::Update(sf::Clock& cc)
{
	butt->Update(cc);
}

void GSSetting::Render(sf::RenderWindow* window)
{
	window->draw(pi);
	butt->Render(window);
}
