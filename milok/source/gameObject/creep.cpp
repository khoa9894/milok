#include "creep.h"

void creep::Init()
{

	//ske->setPosition(100, 400);
}

void creep::Update(float deltaTime)
{
	ske->move(-ske->Velocity().x * deltaTime, 0);
	current->setPosition(sf::Vector2f(ske->getPosition()));
	current->Update(deltaTime);
	if(ske->getPosition().x+64<=0) ske->setPosition(sf::Vector2f (m_startPoint));
	//current = death;
}

void creep::Render(sf::RenderWindow* window)
{
	window->draw(*current);
	window->draw(*ske);
}

skeleton* creep::getSke()
{
	return ske;
}
