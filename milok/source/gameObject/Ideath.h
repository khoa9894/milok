#pragma once

#include "characterStateBase.h"
#include "IPlayer.h"
class Ideath :public characterStateBase {
public:	Ideath(Iplayer* playah);
	void Init();
	void Render(sf::RenderWindow* window);
	void Update(sf::Clock* cc);
	void Reset();
private:
	Iplayer* player;
	animation* cu;
};