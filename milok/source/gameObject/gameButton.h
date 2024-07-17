#pragma once
#include<SFML/Graphics.hpp>
#include"../conector/windowConector.h"
class gameButton :public sf::RectangleShape {
public:	gameButton();
	~gameButton();
	void Init();
	void Update(sf::Clock& cc);
	void Render(sf::RenderWindow* window);
	void touch();
	bool isTouch();
	void setClick(void(*func)());
private:
	void (*gameButtonClick)();
	bool isClick;
};