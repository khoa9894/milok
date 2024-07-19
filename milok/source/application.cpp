
#include "application.h"

void application::Init()
{
    k_window = new sf::RenderWindow(sf::VideoMode(512*2, 256*2), "SFML works!");
    stateStack::GetInstance()->ChangeState(StateTypes::INTRO);
    windowConector::GetInstance()->setWindow(k_window);
  //  rt.loadFromFile("../Data/Textures/idle.png");
   // hi = new animation(rt, 6);
}

void application::Run()
{
    sf::Clock cc;
    Init();
    while (k_window->isOpen())
    {
        sf::Event event;
        while (k_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                k_window->close();
        }
        Update(cc);
        Render();
    }
}
void application::Update(sf::Clock &cc) {
    if (stateStack::GetInstance()->needToChangeState()) {
        stateStack::GetInstance()->PerformStateChange();
    }
    stateStack::GetInstance()->currentState()->Update(cc);
   // hi->Update(cc);
}
void application::Render()
{
    
    k_window->clear(sf::Color::Black);
   
   stateStack::GetInstance()->currentState()->Render(k_window);
  // k_window->draw(*hi);
    k_window->display();
    
}
application:: ~ application() {
    if (k_window != nullptr) delete k_window;
   // if (conc != nullptr) delete conc;
}