#pragma once
#include "gameStateBase.h"
#include <SFML/Graphics.hpp>
#include"stateStack.h"
#include"../gameObject/animation.h"
class GSMenu :public gameStateBase {
public:	GSMenu();
	~GSMenu();
	void Exit();
	void Resume();
	void Pause();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	std::list<gameButton*> buttonList;
	sf::Sprite pi;
	animation* ani;
};