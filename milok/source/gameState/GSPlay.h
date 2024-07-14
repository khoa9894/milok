#pragma once
#include "gameStateBase.h"
#include <SFML/Graphics.hpp>
#include"stateStack.h"
#include"GSMenu.h"
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



};