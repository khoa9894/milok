#pragma once
#include"../gameManage/resourceManage.h"
#include"SFML/Graphics.hpp"
#include"animation.h"
#include"Hitbox.h"

class creep {
public:
	creep() {
		currentTime = 0.0f;
	}
	~creep() {
		current = nullptr;
		if (run != nullptr) delete run;
		if (death != nullptr) delete death;
		if (ske != nullptr) delete ske;
	}
 virtual void Init();
 virtual void Update(float deltaTime);
 virtual void Render(sf::RenderWindow* window);
 virtual skeleton* getSke();
 void setStartPoint(sf::Vector2f point) { m_startPoint = point; }
 void reset();
protected:
	sf::Vector2f m_startPoint;
	animation* current;
	animation* run;
	animation* death;
	skeleton* ske;
	float currentTime;
};