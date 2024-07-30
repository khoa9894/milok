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
	spawn.Init(coll);
	coll.addObj(ccc.getSkeleton());
	
}

void GSPlay::Update(float deltaTime)
{
	
	
	
	if (ccc.getState() != characterStateBase::characterState::ATTACK )
	{
		layer1->Update(3.6f);
		concu.Update(3);
	}
	spawn.Update(deltaTime);
	coll.Update();
	ccc.Update(deltaTime);	
	
}

void GSPlay::Render(sf::RenderWindow* window)
{   
	concu.Render(window);
	ccc.Render(window);
	spawn.Render(window);
	layer1->Render(*window);
	
	
	
}
