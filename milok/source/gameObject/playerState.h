#pragma once
#include "characterStateBase.h"
class playerState:public {
public:
	void changeState(characterStateBase::characterState nextState);
	void Update(sf::Clock* cc);
	void Render(sf::RenderWindow* window);

};