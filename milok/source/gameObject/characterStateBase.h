#pragma once
#include <SFML/Graphics.hpp>

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
private:
	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderWindow* window) = 0;
	virtual void Reset() = 0;
};