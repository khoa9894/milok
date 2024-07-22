#pragma once
#include "characterStateBase.h"
#include "Iplayer.h"
class playerState:public Iplayer {
public:
	playerState();
	~playerState();
	void changeState(characterStateBase::characterState nextState);
	void Init();
	void Update(sf::Clock* cc);
	void Render(sf::RenderWindow* window);
	characterStateBase::characterState getState();
private:
	void performStateChange();
	characterStateBase::characterState current;
	characterStateBase::characterState nextState;
	characterStateBase* runState;
	characterStateBase* jumpState;
	characterStateBase* fallState;
	characterStateBase* death;
	characterStateBase* currentState;
	characterStateBase* attackState;
};