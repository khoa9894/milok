#pragma once
#include "gameStateBase.h"
#include <SFML/Graphics.hpp>
#include"stateStack.h"
#include"GSMenu.h"
class GSIntro: public gameStateBase {
public:
	GSIntro() {};
   ~GSIntro() {};
	void Exit();
	 void Resume() ;
     void Pause();
	 void Init();
	 void Update(sf::Clock& cc);
	 void Render(sf::RenderWindow* window);
private:
	sf::Sprite sprite;
	sf::Text text;

};