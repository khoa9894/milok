#pragma once
#pragma once
#include "gameStateBase.h"
#include <SFML/Graphics.hpp>
#include"stateStack.h"
#include <SFML/Network.hpp>
#include <SFML/Network/IpAddress.hpp>
class GSAbout : public gameStateBase {
public:
	GSAbout() ;
	~GSAbout() ;
	void Exit();
	void Resume();
	void Pause();
	void Init();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* window);
//	void openGitHubLink(const std::string& url);
 private: 
	   sf::Sprite pi;
	   gameButton *butt;
	   gameButton* ex;


};