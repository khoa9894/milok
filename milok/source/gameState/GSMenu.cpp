#include "GSMenu.h"
GSMenu::GSMenu() {

}
GSMenu::~GSMenu() {

}
void GSMenu::Exit()
{
}

void GSMenu::Resume()
{
}

void GSMenu::Pause()
{
}

void GSMenu::Init()
{
	printf("cc");
	shape.setRadius(100);
	shape.setFillColor(sf::Color::Red);

}

void GSMenu::Update(sf::Clock& cc)
{
}

void GSMenu::Render(sf::RenderWindow* window)
{
	window->draw(shape);
}
