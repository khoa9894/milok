#pragma once
#include <SFML/Graphics.hpp>
#include "../gameManage/resourceManage.h"
#include "animation.h"
class characterStateBase {
public:
	enum characterState {
		RUN ,
		JUMP,
		FALL,
		DEATH,
		ATTACK,
		SNULL,
	};
	virtual void Init() = 0;
	virtual void Update(sf::Clock *cc) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};