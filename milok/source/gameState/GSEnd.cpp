#include "GSEnd.h"

GSEnd::GSEnd()
{
}

GSEnd::~GSEnd()
{
}

void GSEnd::Exit()
{
}

void GSEnd::Resume()
{
}

void GSEnd::Pause()
{
}

void GSEnd::Init()
{   //restart
	gameButton* button;
    button = new gameButton();
	button->Init("restart");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(sf::Vector2f(971 / 2 + 50-100, 500 / 2 + 500 / 10 + 60 - 40));
	button->setClick([]() {
	stateStack::GetInstance()->PopState();
	stateStack::GetInstance()->ChangeState(StateTypes::PLAY);
	ScoreManager::GetInstance()->UpdateHighScore();
	ScoreManager::GetInstance()->writeFile();
	 });
	buttonList.push_back(button);
	//menu
	 button = new gameButton();
	button->Init("menu");
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(sf::Vector2f(971 / 2 + 300-100, 500 / 2 + 500 / 10 + 60 - 40));
	button->setClick([]() {stateStack::GetInstance()->ChangeState(StateTypes::MENU); 
	ScoreManager::GetInstance()->UpdateHighScore();
	ScoreManager::GetInstance()->writeFile(); });
	buttonList.push_back(button);
   //highscore
	yourScore.setFont(*resourceManage::GetInstance()->getFont("ARCADE_N"));
	yourScore.setFillColor(sf::Color::Red);
	yourScore.setString("Your Score: "+std::to_string(ScoreManager::GetInstance()->getCurrentScore()));
	yourScore.setPosition(50, 50);
	//your
	bestScore.setFont(*resourceManage::GetInstance()->getFont("ARCADE_N"));
	bestScore.setFillColor(sf::Color::Red);
	bestScore.setString("Best score: 90" );
	bestScore.setPosition(50, 100);
	backGround.setTexture(*resourceManage::GetInstance()->gtTexture("cucc"));
	//backGround.setPosition(512 * 2, 256 * 2);
}

void GSEnd::Update(float deltaTime)
{
	for (auto it : buttonList) {
		it->Update(deltaTime);
	}
}

void GSEnd::Render(sf::RenderWindow* window)
{
	window->draw(backGround);
	for (auto it : buttonList) {
		it->Render(window);
	}
	window->draw(yourScore);
	window->draw(bestScore);
	
}
