#include "Boss.h"

void Boss::Init()
{
	walk = new animation2(*resourceManage::GetInstance()->gtTexture("walk_look up"), 5, 4, 0.1);
	walk->setScale(2,2);
	ske = new skeleton(sf::Vector2i(212, 209));
	ske->setPosition(1024+500, 256);
	ske->Init(sf::Vector2f(212, 209));
	//bull.Init(coll);
	walk->setPosition(ske->getPosition());
}

void Boss::Render(sf::RenderWindow* window)
{
	//bull.Render(window);
	window->draw(*walk);
}

void Boss::Update(float deltaTime,bool check)
{
	if (check== 1) {
		if (ske->getPosition().x >= 512) {
			ske->move(-(ske->Velocity().x * deltaTime), 0);
			walk->setPosition(ske->getPosition());
		}
		walk->Update(deltaTime);
		
}
	
}
