#pragma once
#include "../gameManage/singleton.h"
#include <list>
#include "gameStateBase.h"
class stateStack : public CSingleton<stateStack>  {
private:
    gameStateBase *k_currentState;
	std::list <gameStateBase*> k_stack;
	gameStateBase* k_nexState;
    bool isrun;
public:
	stateStack();
	~stateStack();
	void ChangeState(gameStateBase* state);
	void ChangeState(StateTypes st);
	void PushState(StateTypes st);
	void PopState();
	void PerformStateChange();
	
};