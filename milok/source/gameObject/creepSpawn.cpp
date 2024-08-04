#include "creepSpawn.h"

creepSpawn::creepSpawn()
{
	numCreep = 10;
	timeSpawn = 1.0f;
	currentTime = 0.0f;
}
creepSpawn::~creepSpawn()
{
	for (auto it : bat) {
		if (it != nullptr) delete it;
	}
	for (auto it : cobra) {
		if (it != nullptr) delete it;
	}
	currentTime = 0.0f;
}

void creepSpawn::Init(CollisionManager& coll)
{
	for (int i = 0; i < 10; i++) {
		creep* crep = new Bat();
		crep->Init();
		coll.addObj(crep->getSke());
		bat.push_back(crep);
		crep = new cobraCreep();
		crep->Init();
		coll.addObj(crep->getSke());
		cobra.push_back(crep);
}

}

void creepSpawn::Update(float deltaTime)
{

	currentTime += deltaTime;
	if (currentTime >= 2) {
		spawnBat();
		spawnCobra();
		currentTime = 0.0f;
	}
	for (auto it : cobra) {
		it->Update(deltaTime);
	}
	for (auto it : bat) {
		it->Update(deltaTime);
	}
}

void creepSpawn::Render(sf::RenderWindow* window)
{
	for (auto it : cobra) {
		it->Render(window);
	}
	for (auto it : bat) {
		it->Render(window);
	}
}

void creepSpawn::spawnCobra()
{
	creep* crep = nullptr;
	for (auto it : cobra) {
		if (it->getSke()->isAlive() == 0) {
			crep = it;
			break;
		}
	}
	if (crep == nullptr) return;
	crep->getSke()->setAlive(1);
	crep->setStartPoint(sf::Vector2f(1024+rand()%100, 432));
	crep->getSke()->setVelocity(sf::Vector2f(200 + rand() % 200, 200));
	crep->reset();
//	crep = nullptr;

}

void creepSpawn::spawnBat()
{
	creep* crep = nullptr;
	for (auto it : bat) {
		if (it->getSke()->isAlive() == 0) {
			crep = it;
			break;
		}
	}
	if (crep == nullptr) return;
	crep->getSke()->setAlive(1);
	crep->setStartPoint(sf::Vector2f(1024,200+rand()%100));
	crep->getSke()->setVelocity(sf::Vector2f(200 + rand() % 200, 200));
	crep->reset();
//	crep = nullptr;
}
