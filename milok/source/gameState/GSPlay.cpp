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
	
}

void GSPlay::Update(sf::Clock& cc)
{
	concu.Update(0.05);
}

void GSPlay::Render(sf::RenderWindow* window)
{
	concu.Render(window);
	
}
