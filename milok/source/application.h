#pragma once
#include<SFML/Graphics.hpp>
#include "gameManage/resourceManage.h"
class application
{
private: sf::RenderWindow *k_window;
	   sf::Sprite conc;
public: 
	void Init();
	void Run();
	void Render();
	~application();
};

