#pragma once
#include <list>
#include "HitBox.h"

class CollisionManager {
public:
	void addObj(skeleton* hitBox);
	bool checkCollision(skeleton* a, skeleton* b);
	void Update();
private:
	std::list<skeleton*> m_listObj;
};