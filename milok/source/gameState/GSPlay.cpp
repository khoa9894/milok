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
	text.setFont(*resourceManage::GetInstance()->getFont("ARCADE_N"));
	text.setFillColor(sf::Color::Red);
	text.setString(std::to_string(score));
//	text.setScale(2, 2);
	text.setPosition(50,50);
	concac.Init();
	concu.Init();
	ccc.Init();
	layer1 = new layer();
	layer1->Init("16", 1);
	spawn.Init(coll);
	coll.addObj(ccc.getSkeleton());
    boss.Init();
	bull.Init(coll);
}

void GSPlay::Update(float deltaTime)
{
	currentTime += deltaTime;
	if (ccc.getSkeleton()->isAlive() == 1) {
		if (currentTime >= 0.5) {
			score++;
			text.setString(std::to_string(score));
			currentTime -= 0.5;
		}
		if (score >= 25) {
			check = true;
		}
	}
	else ScoreManager::GetInstance()->setCurrentScore(score);
	if (ccc.getState() != characterStateBase::characterState::ATTACK && ccc.getSkeleton()->isAlive() == 1)
	{
		layer1->Update(3.6f);
		concu.Update(3);
		concac.Update(3);
	}
	spawn.Update(deltaTime);
	coll.Update();
	ccc.Update(deltaTime);	
	bull.Update(deltaTime,check);
	boss.Update(deltaTime,check);

	
}

void GSPlay::Render(sf::RenderWindow* window)
{
	
	concu.Render(window);
	boss.Render(window);
	concac.Render(window);
	ccc.Render(window);
	spawn.Render(window);
	bull.Render(window);
	layer1->Render(*window);
	window->draw(text);
	
}
