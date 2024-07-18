#pragma once
#include "gameStateBase.h"
#include <SFML/Graphics.hpp>
#include"stateStack.h"
class GSMenu :public gameStateBase {
public:	GSMenu();
	~GSMenu();
	void Exit();
	void Resume();
	void Pause();
	void Init();
	void Update(sf::Clock& cc);
	void Render(sf::RenderWindow* window);
private:
	std::list<gameButton*> buttonList;
	sf::Sprite pi;
};