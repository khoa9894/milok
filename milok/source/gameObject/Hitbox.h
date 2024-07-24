#pragma once
#include "../gameManage/resourceManage.h"
class skeleton :public sf::RectangleShape {
public:	skeleton(sf::Vector2i size);
	~skeleton();
	void Init(sf::Vector2f velocity);
	sf::Vector2f Velocity();
private:
	sf::Vector2f velocity;
};