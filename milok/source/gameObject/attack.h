#pragma once
#pragma once

#include "characterStateBase.h"
#include "IPlayer.h"
class Iattack :public characterStateBase {
public:	Iattack(Iplayer* playah);
	void Init();
	void Render(sf::RenderWindow* window);
	void Update(sf::Clock* cc);
	void Reset();
private:
	Iplayer* player;
	animation* cu;
};