#include "gameButton.h"

gameButton::gameButton()
{
    isClick = false;
}

gameButton::~gameButton()
{
}

void gameButton::Init(std::string name)
{
    this->setSize(sf::Vector2f(214/2, 215/2));
   this->setTexture(resourceManage::GetInstance()->gtTexture(name));
    
  
}
void gameButton::Render(sf::RenderWindow* window) {
    window->draw(*this);
}
void gameButton::Update(sf::Clock& cc)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        touch();
    }
}

void gameButton::touch()
{
    isClick = false;
    if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*windowConector::GetInstance()->getWindow()))) {
        gameButtonClick();
        isClick = true;
    }
}

bool gameButton::isTouch()
{
    return false;
}

void gameButton::setClick(void(*func)())
{
    gameButtonClick = func;
}
