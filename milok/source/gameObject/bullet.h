#pragma once
#include "../gameManage/resourceManage.h"
#include "animation2.h"
#include "Hitbox.h"
class bullet {
public:
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
	~bullet() {
		{
			current = nullptr;
			if (bombFall != nullptr) delete bombFall;
			if (fire != nullptr) delete fire;
			if (ske != nullptr) delete ske;
		}
	}
	bullet() {
		currentTime = 0.0f;
		startPoint =sf::Vector2f (100, 100);
	}
	skeleton* getSke() {
		return ske;
	}
	void setStartPoint(sf::Vector2f point) { startPoint = point; }
	sf::Vector2f getStartPoint() { return startPoint; }
	void reset();
private:
	sf::Vector2f startPoint;
	float currentTime;
	animation2* current;
	animation2* bombFall;
	animation2* fire;
	skeleton* ske;
};