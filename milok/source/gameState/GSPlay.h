#pragma once
#include"stateStack.h"
#include "../gameObject/playerState.h"
#include "../gameManage/background.h"
#include "../gameObject/creepSpawn.h"
#include "../gameObject/Boss.h"
#include "../gameManage/background2.h"
#include "../gameObject/BulletSpawn.h"
#include "../gameObject/scoreManagecpp.h"
class GSPlay : public gameStateBase {
public:
	GSPlay() {
		currentTime = 0.0f;
		check = 0;
		score = 0;
	}
	~GSPlay() {
		if (layer1 != nullptr) delete layer1;
	}
	void Exit();
	void Resume();
	void Pause();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	background concu;
	background2 concac;
	playerState ccc;
	layer* layer1;
	CollisionManager coll;
	creepSpawn spawn;
	Boss boss;
	bulletSpawn bull;
	float currentTime;
	bool check;
	sf::Text text;
	
	int score;
//nimation* penguin;
};