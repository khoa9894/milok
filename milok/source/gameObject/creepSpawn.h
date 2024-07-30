#pragma once
#include"cobra.h"
#include"Bat.h"
#include"collision.h"
class creepSpawn {
public:
	creepSpawn();
	~creepSpawn();
	void Init(CollisionManager &coll);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list <creep*> cobra;
	std::list <creep*>bat;
	void spawnCobra();
	void spawnBat();
	int numCreep;
	float timeSpawn;
	float currentTime;
};