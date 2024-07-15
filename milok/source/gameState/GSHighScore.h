#pragma once
#pragma once
#pragma once
#include "gameStateBase.h"
#include <SFML/Graphics.hpp>
#include"stateStack.h"

class GSHighScore : public gameStateBase {
public:
	GSHighScore();
	~GSHighScore();
	void Exit();
	void Resume();
	void Pause();
	void Init();
	void Update(sf::Clock& cc);
	void Render(sf::RenderWindow* window);
private:



};