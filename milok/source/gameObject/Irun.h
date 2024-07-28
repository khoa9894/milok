#pragma once

#include "characterStateBase.h"
#include "IPlayer.h"
class Irun :public characterStateBase {
public:
	Irun (Iplayer* playah);
	void Init();
	void Render(sf::RenderWindow* window);
	void Update(float deltaTime);
	void Reset();
private:
	Iplayer* player;
	animation* cu;
};