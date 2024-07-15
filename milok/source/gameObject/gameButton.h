#pragma once
#include<SFML/Graphics.hpp>
#include"../conector/windowConector.h"
class gameButton :public sf::RectangleShape {
	gameButton();
	~gameButton();
	void Init();
	void Update(sf::Clock& cc);
	void Render(sf::RenderWindow* window);
	void touch();
	bool isTouch();
private:
	void (*gameButtonClick)();
	bool isClick;
};