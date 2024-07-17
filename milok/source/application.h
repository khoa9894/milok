#pragma once
#include<SFML/Graphics.hpp>
#include "gameManage/resourceManage.h"
#include "gameState/stateStack.h"
#include "gameObject/animation.h"
class application
{
private: sf::RenderWindow *k_window;
	  // sf::Texture rt;
	 //  animation *hi;
public: 
	void Init();
	void Run();
	void Render();
	~application();
	void Update(sf::Clock &cc);
};

