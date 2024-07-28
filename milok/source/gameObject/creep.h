#pragma once
#include"../gameManage/resourceManage.h"
#include"SFML/Graphics.hpp"
#include"animation.h"
#include"Hitbox.h"

class creep {
public:
 virtual void Init();
 virtual void Update(float deltaTime);
 virtual void Render(sf::RenderWindow* window);
 virtual skeleton* getSke();
 void setStartPoint(sf::Vector2f point) { m_startPoint = point; }
protected:
	sf::Vector2f m_startPoint;
	animation* current;
	animation* run;
	animation* death;
	skeleton* ske;
};