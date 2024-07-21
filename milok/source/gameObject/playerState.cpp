#include "playerState.h"
#include "Irun.h"
playerState::playerState() {
	nextState = characterStateBase::characterState::SNULL;
	runState = new Irun(this);
//	jumpState = new Ijump(this);
	currentState = runState;
}
playerState::~playerState() {
	if (runState != nullptr) delete runState;
}
void playerState::changeState(characterStateBase::characterState nextState)
{
	this->nextState = nextState;
}
void playerState::Init() {
	runState->Init();
//	jumpState->Init();
}
void playerState::Update(sf::Clock* cc)
{
	//performStateChange();
	currentState->Update(cc);

}

void playerState::Render(sf::RenderWindow* window)
{
	currentState->Render(window);
}

void playerState::performStateChange()
{
	if (nextState != characterStateBase::characterState::SNULL) {
		switch (nextState) {
		case characterStateBase::characterState::RUN:
			currentState = runState;
			break;
		}
	/*	default:
			break;*/
	}
	nextState=characterStateBase::characterState::SNULL;
	currentState->Reset();

}
