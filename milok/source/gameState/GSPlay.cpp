#include "GSPlay.h"


void GSPlay::Exit()
{
}

void GSPlay::Resume()
{
}

void GSPlay::Pause()
{
}

void GSPlay::Init()
{
	
	concu.Init();
	ccc.Init();
	layer1 = new layer();
	layer1->Init("16", 1);
	creep* bot = new cobraCreep();
	listCreep.push_back(bot);
	bot = new Bat();
	listCreep.push_back(bot);
	//hi.Init();
	for (auto it : listCreep) {
		it->Init();
	}
	
}

void GSPlay::Update(float deltaTime)
{
	
	

	if (ccc.getState() != characterStateBase::characterState::ATTACK )
	{
		layer1->Update(3.6f);
		concu.Update(3);
	}
	//hi.Update(deltaTime);
	ccc.Update(deltaTime);
	for (auto it : listCreep) {
		it->Update(deltaTime);
	}
}

void GSPlay::Render(sf::RenderWindow* window)
{
	concu.Render(window);
	ccc.Render(window);
//	hi.Render(window);
	layer1->Render(*window);
	for (auto it : listCreep) {
		it->Render(window);
	}
	
	
}
