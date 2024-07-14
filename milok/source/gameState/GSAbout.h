#pragma once
#pragma once
#include "gameStateBase.h"
#include <SFML/Graphics.hpp>
#include"stateStack.h"

class GSAbout : public gameStateBase {
public:
	GSAbout() ;
	~GSAbout() ;
	void Exit();
	void Resume();
	void Pause();
	void Init();
	void Update(sf::Clock& cc);
	void Render(sf::RenderWindow* window);
private:



};