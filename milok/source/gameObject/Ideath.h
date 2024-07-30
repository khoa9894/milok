#pragma once

#include "characterStateBase.h"
#include "IPlayer.h"
#include"../gameState/stateStack.h"
class Ideath :public characterStateBase {
public:	Ideath(Iplayer* playah);
	void Init();
	void Render(sf::RenderWindow* window);
	void Update(float deltaTime);
	void Reset();
private:
	Iplayer* player;
	animation* cu;
	float time;
};