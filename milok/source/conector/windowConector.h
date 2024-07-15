#pragma once
#include "../gameManage/singleton.h"
#include <SFML/Graphics.hpp>
class windowConector :public CSingleton<windowConector> {
private: sf::RenderWindow* m_window;
public: 
	windowConector();
	void setWindow(sf::RenderWindow* window);
	sf::RenderWindow* getWindow();
};