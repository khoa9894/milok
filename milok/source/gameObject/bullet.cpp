#include "bullet.h"

void bullet::Init()
{
	bombFall = new animation2(*resourceManage::GetInstance()->gtTexture("fb"), 6, 1, 0.09);
	bombFall->rotate(90);
	bombFall->setScale(2, 2);
	fire = new animation2(*resourceManage::GetInstance()->gtTexture("Fire+Sparks-Sheet"), 4, 5, 0.09);
	current = bombFall;
	ske = new skeleton(sf::Vector2i(12, 10));
	ske->Init(sf::Vector2f(100, 200));
	ske->setPosition(sf::Vector2f(500, -90));
	ske->setTag(BULLET);
	ske->setAlive(1);
	current->setPosition(ske->getPosition());
}

void bullet::Update(float deltaTime)
{    
	if (ske->isAlive() == 1) {
		ske->move(0, ske->Velocity().y * deltaTime);
		if (ske->getPosition().y >= 430) {
			ske->setAlive(0);
		}
	}
	else {
		ske->size(sf::Vector2f(15, 20));
		current = fire;
		currentTime += deltaTime;
		if (currentTime >= 2) {
			reset();
			currentTime = 0.0f;
		}
	}
	current->Update(deltaTime);
	current->setPosition(ske->getPosition());
}

void bullet::Render(sf::RenderWindow* window)
{
	window->draw(*current);
	window->draw(*ske);
}
void bullet::reset() {
	ske->setPosition(startPoint);
	current = bombFall;
	ske->setAlive(1);
	ske->size(sf::Vector2f(12, 10));
 }