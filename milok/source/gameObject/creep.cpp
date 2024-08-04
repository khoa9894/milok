#include "creep.h"

void creep::Init()
{

	//ske->setPosition(100, 400);
	//currentTime = 0.0f;
}

void creep::Update(float deltaTime)
{
	if (ske->isAlive() == 1) {
		current = run;
		ske->move(-ske->Velocity().x * deltaTime, 0);
		if (ske->getPosition().x + 64 <= 0) ske->setAlive(0);		
}
	else {
		currentTime += deltaTime;
		current = death;
		if (currentTime >= 1) {
			reset();
			ske->setAlive(1);
			currentTime = 0.0f;	
		}
	}
	current->setPosition(ske->getPosition());
	current->Update(deltaTime);
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
void creep::reset() {
	ske->setPosition(sf::Vector2f(m_startPoint));
	current = run;
	
}