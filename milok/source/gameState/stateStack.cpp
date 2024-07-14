#include "stateStack.h"
#include "gameStateBase.h"
stateStack::stateStack()
{
	k_currentState = nullptr;
	k_nexState = nullptr;
	isrun = true;
}

stateStack::~stateStack()
{
	if (k_currentState != nullptr) delete k_currentState;
	if (k_nexState != nullptr) delete k_nexState;
	while (!k_stack.empty()) {
		delete k_stack.back();
		k_stack.pop_back();
	}
}

void stateStack::ChangeState(gameStateBase* state)
{
	k_nexState = state;
}

void stateStack::ChangeState(StateTypes st)
{
	gameStateBase* gs = gameStateBase::CreateState(st);
	ChangeState(gs);
}

void stateStack::PushState(StateTypes st)
{
	gameStateBase *gs= gameStateBase::CreateState(st);
	if (!k_stack.empty()) {
		k_stack.back()->Pause();
	}
	k_nexState = gs;
}

void stateStack::PopState()
{
	if (!k_stack.empty()) {
		k_stack.back()->Exit();
		k_stack.pop_back();
	}
	if (!k_stack.empty()) {
		k_stack.back()->Resume();
	}
	k_currentState = k_stack.back();
}

void stateStack::PerformStateChange()
{
	if (k_nexState != nullptr) {
		if (!k_stack.empty()) {
			k_stack.back()->Exit();
		}
		k_stack.push_back(k_nexState);
		k_stack.back()->Init();
		k_currentState = k_nexState;
		k_nexState = nullptr;
	}
}
bool stateStack::needToChangeState() {
	return k_nexState != nullptr;
}
gameStateBase* stateStack::currentState() const
{
	return k_currentState;
}
gameStateBase* stateStack::nextState() const
{
	return k_nexState;
}
bool stateStack::hasState() {
	return k_stack.size() > 0;
}
