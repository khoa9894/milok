#pragma once
#pragma once
#pragma once
#include "gameStateBase.h"
#include <SFML/Graphics.hpp>
#include"stateStack.h"
#include "../gameObject/scoreManagecpp.h"

class GSEnd : public gameStateBase {
public:
	GSEnd();
	~GSEnd();
	void Exit();
	void Resume();
	void Pause();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
private:
	sf::Sprite backGround;
	std::list<gameButton*> buttonList;
	sf::Text yourScore;
	sf::Text bestScore;



};