#pragma once
#include <SFML/Graphics.hpp>
#include "../conector/windowConector.h"
#include "../gameObject/gameButton.h"
enum StateTypes
{
	INVALID = 0,
	INTRO,
	MENU,
	PLAY,
	SETTING,
	ABOUT,
	HIGHSCORE,
	END,
};
class gameStateBase {
public:
	gameStateBase() {};
	virtual	~gameStateBase() {};
  virtual void Exit() = 0;
  virtual void Resume() = 0;
  virtual void Pause() = 0;
  virtual void Init() = 0;
  virtual void Update(float deltaTime) = 0;
  virtual void Render(sf::RenderWindow* window) = 0;
  static gameStateBase* CreateState(StateTypes st);
};