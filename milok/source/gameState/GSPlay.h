#pragma once
#include "gameStateBase.h"
#include <SFML/Graphics.hpp>
#include"stateStack.h"
#include "../gameObject/playerState.h"
#include"GSMenu.h"
#include "../gameManage/background.h"
class GSPlay : public gameStateBase {
public:
	GSPlay() {};
	~GSPlay() {};
	void Exit();
	void Resume();
	void Pause();
	void Init();
	void Update(sf::Clock& cc);
	void Render(sf::RenderWindow* window);
private:
	background concu;
	playerState ccc;
	layer* layer1;

};