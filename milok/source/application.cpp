
#include "application.h"

void application::Init()
{
    k_window = new sf::RenderWindow (sf::VideoMode(600, 600), "SFML works!");
    conc.setTexture(*resourceManage::GetInstance()->gtTexture("Run"));
   
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

        Render();
    }
}

void application::Render()
{
    
    k_window->clear(sf::Color::White);
    k_window->draw(conc);
    k_window->display();
}
application:: ~ application() {
    if (k_window != nullptr) delete k_window;
   // if (conc != nullptr) delete conc;
}