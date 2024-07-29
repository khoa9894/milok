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
	//fast = new IrunFast(this);
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
	//fast->Init();
	death->Init();
	ske = new skeleton(sf::Vector2i( 20,35));
	ske->Init(sf::Vector2f(250, 100));
	ske->setPosition(100, 400);
	ske->setTag(PLAYER);
	ske->setAlive(1);
	ske->setAttack(0);

}
void playerState::Update( float deltaTime)
{
	performStateChange();
	currentState->Update(deltaTime);

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
			ske->setAttack(0);
			current = characterStateBase::characterState::RUN;
			break;
		case characterStateBase::characterState::JUMP:
			currentState = jumpState;
			ske->setAttack(0);
			current = characterStateBase::characterState::JUMP;
			break;
		case characterStateBase::characterState::FALL:
			currentState = fallState;
			ske->setAttack(0);
			current = characterStateBase::characterState::FALL;
			break;
		case characterStateBase::characterState::DEATH:
			currentState = death;
			ske->setAttack(0);
			current = characterStateBase::characterState::DEATH;
			break;
		case characterStateBase::characterState::ATTACK:
			currentState = attackState;
			ske->setAttack(1);
			current = characterStateBase::characterState::ATTACK;
			break;
		/*case characterStateBase::characterState::FAST:
			currentState = fast;
			current = characterStateBase::characterState::FAST;
			break;*/
		default:
			break;
		}
	}
	nextState=characterStateBase::characterState::SNULL;
	//currentState->Reset();

}
