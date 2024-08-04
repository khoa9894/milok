#pragma once
#include "animation2.h"
#include "../gameManage/resourceManage.h"
#include "Hitbox.h"
#include "collision.h"
#include "BulletSpawn.h"
class Boss {
public:	void Init();
	  void Render(sf::RenderWindow* window);
	  void Update(float deltaTime, bool check);
	//  bulletSpawn getBull();
private:
	animation2* walk;
	skeleton* ske;
	bulletSpawn bull;
};
