#pragma once
#pragma once
#include "gameStateBase.h"
#include <SFML/Graphics.hpp>
#include"stateStack.h"
class GSSetting : public gameStateBase {
public:
	GSSetting();
	~GSSetting() ;
	void Exit();
	void Resume();
	void Pause();
	void Init();
	void Update(sf::Clock& cc);
	void Render(sf::RenderWindow* window);
private:



};