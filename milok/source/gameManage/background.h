#pragma once
#include"layer.h"
#include<list>
#include "../gameObject/Boss.h"
#include<SFML/Graphics.hpp>
class background {
public:	void Init();
	void Update(float speed);
	void Render(sf::RenderWindow *window);
private:
	std::list<layer*> layerList;

};