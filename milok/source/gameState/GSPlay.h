#pragma once
#include"stateStack.h"
#include "../gameObject/playerState.h"
#include "../gameManage/background.h"
#include"../gameObject/creep.h"
#include"../gameObject/Bat.h"
#include"../gameObject/cobra.h"
#include"../gameObject/collision.h"
class GSPlay : public gameStateBase {
public:
//	GSPlay() {};
//	~GSPlay();
	void Exit();
	void Resume();
	void Pause();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	background concu;
	playerState ccc;
	layer* layer1;
	std::list<creep*> listCreep;
	CollisionManager coll;
	
//nimation* penguin;
};