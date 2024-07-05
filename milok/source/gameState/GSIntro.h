#pragma once
#include "gameStateBase.h"
#include <SFML/Graphics.hpp>
class GSIntro: public gameStateBase {
public:
	GSIntro() {};
	~GSIntro() {};
	void Exit();
	 void Resume() ;
     void Pause();
	 void Init();
	 void Update();
	 void Render(sf::RenderWindow* window);

};