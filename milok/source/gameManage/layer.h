#pragma once
#include <SFML/Graphics.hpp>
#include"resourceManage.h"
class layer {
public :void Init(std::string name,int n);
	void Update(float speed);
	void Render(sf::RenderWindow& window);
private:
	sf::Sprite pi;
	sf::Sprite pi1;
};