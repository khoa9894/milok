#include "GSAbout.h"
GSAbout::GSAbout() {

}
GSAbout::~GSAbout()
{
	//if (pi != nullptr) delete pi;
	if (butt != nullptr) delete butt;
	if (ex != nullptr) delete ex;
}

void GSAbout::Exit()
{
}

void GSAbout::Resume()
{
}

void GSAbout::Pause()
{
}

void GSAbout::Init()
{
	pi.setTexture(*resourceManage::GetInstance()->gtTexture("cucc"));
	butt = new gameButton();
	butt->Init("close");
	butt->setOrigin(butt->getSize() / 2.f);
	butt->setPosition(sf::Vector2f(850, 70));
	butt->setClick([]() {stateStack::GetInstance()->PopState(); });
}

void GSAbout::Update(sf::Clock& cc)
{
	butt->Update(cc);
}

void GSAbout::Render(sf::RenderWindow* window)
{
	window ->draw(pi);
	butt->Render(window); 

}
