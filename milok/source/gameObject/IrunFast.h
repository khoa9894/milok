#pragma once

#include "characterStateBase.h"
#include "IPlayer.h"
class IrunFast :public characterStateBase {
public:	IrunFast(Iplayer* playah);
	  void Init();
	  void Render(sf::RenderWindow* window);
	  void Update(float deltaTime);
	  void Reset();
private:
	Iplayer* player;
	animation* cu;
};