 #pragma once
#include<SFML/Graphics.hpp>
#include"../conector/windowConector.h"
#include"../gameManage/resourceManage.h"
class gameButton :public sf::RectangleShape {
public:	gameButton();
	~gameButton();
	void Init(std::string name);
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);    
	void touch();
	bool isTouch();
	void setClick(void(*func)());
private:
	void (*gameButtonClick)();
	bool isClick;
	
};