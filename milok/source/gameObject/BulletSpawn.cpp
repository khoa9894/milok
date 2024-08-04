#include "BulletSpawn.h"

bulletSpawn::bulletSpawn()
{
	currentTime = 0.0f;
}

bulletSpawn::~bulletSpawn()
{
	for (auto it : bulletList) {
		if (it != nullptr) delete it;
	}
}

void bulletSpawn::Init(CollisionManager& coll)
{
	for (int i = 0; i < 10; i++) {
		bullet* bull = new bullet();
		bull->Init();
		coll.addObj(bull->getSke());
		bulletList.push_back(bull);
	}
}

void bulletSpawn::Update(float deltaTime,bool check)
{
	if (check) {
		currentTime += deltaTime;
		if (currentTime >=4) {
			spawnBullet();
			currentTime = 0.0f;
		}
		for (auto it : bulletList) {
			it->Update(deltaTime);
		}
	}
	
}

void bulletSpawn::Render(sf::RenderWindow* window)
{
	for (auto it : bulletList) {
		it->Render(window);
	}
}

void bulletSpawn::spawnBullet()
{
	bullet* bullet = nullptr;
	for (auto it : bulletList) {
		if (it->getSke()->isAlive() == 0) {
			bullet = it;
			break;
		}
	}
	if (bullet == nullptr) return;
	bullet->getSke()->setAlive(1);
	bullet->setStartPoint(sf::Vector2f(500+rand() % 1024, -40));
	bullet->reset();

}
