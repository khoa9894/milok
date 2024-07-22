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
}

void GSPlay::Update(sf::Clock& cc)
{
	
	if (ccc.getState() != characterStateBase::characterState::ATTACK)
	{
		layer1->Update(0.1);
		concu.Update(0.05);
	}
	ccc.Update(&cc);
}

void GSPlay::Render(sf::RenderWindow* window)
{
	concu.Render(window);
	ccc.Render(window);
	layer1->Render(*window);
	
	
}
