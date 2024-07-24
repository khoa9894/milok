#include "playerState.h"
#include "Irun.h"
#include "Ijump.h"
#include "Ifall.h"
#include "Ideath.h"
#include "attack.h"
playerState::playerState() {
	nextState = characterStateBase::characterState::SNULL;
	current = characterStateBase::characterState::SNULL;
	runState = new Irun(this);
	jumpState = new Ijump(this);
	fallState = new Ifall(this);
	attackState = new Iattack(this);
	death = new Ideath(this);
	currentState = runState;
}
characterStateBase::characterState playerState::getState() {
	return current;
}
playerState::~playerState() {
	if (runState != nullptr) delete runState;
	if (jumpState != nullptr) delete jumpState;
	if (fallState != nullptr) delete fallState;
	if (attackState != nullptr) delete attackState;
	if (death != nullptr) delete death;
	currentState = nullptr;
}
skeleton* playerState:: getSkeleton() {
	return ske;
}
void playerState::changeState(characterStateBase::characterState nextState)
{
	this->nextState = nextState;
}
void playerState::Init() {
	runState->Init();
	jumpState->Init();
	fallState->Init();
	attackState->Init();
	death->Init();
	ske = new skeleton(sf::Vector2i( 64, 44));
	ske->Init(sf::Vector2f(3, 200));
}
void playerState::Update(sf::Clock* cc)
{
	performStateChange();
	currentState->Update(cc);

}

void playerState::Render(sf::RenderWindow* window)
{
	currentState->Render(window);
	window->draw(*ske);
}

void playerState::performStateChange()
{
	if (nextState != characterStateBase::characterState::SNULL) {
		switch (nextState) {
		case characterStateBase::characterState::RUN:
			currentState = runState;
			current = characterStateBase::characterState::RUN;
			break;
		case characterStateBase::characterState::JUMP:
			currentState = jumpState;
			current = characterStateBase::characterState::JUMP;
			break;
		case characterStateBase::characterState::FALL:
			currentState = fallState;
			current = characterStateBase::characterState::FALL;
			break;
		case characterStateBase::characterState::DEATH:
			currentState = death;
			current = characterStateBase::characterState::DEATH;
			break;
		case characterStateBase::characterState::ATTACK:
			currentState = attackState;
			current = characterStateBase::characterState::ATTACK;
			break;
		default:
			break;
		}
	}
	nextState=characterStateBase::characterState::SNULL;
	//currentState->Reset();

}
