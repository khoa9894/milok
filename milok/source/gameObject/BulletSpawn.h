#pragma once
#include "bullet.h"
#include "collision.h"
class bulletSpawn {
public:
	bulletSpawn();
	~bulletSpawn();
	void Init(CollisionManager &coll);
	void Update(float deltaTime,bool check);
	void Render(sf::RenderWindow* window);
private:
	void spawnBullet();
	std::list<bullet*> bulletList;
	float currentTime;

};