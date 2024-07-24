#include "Hitbox.h"

skeleton::skeleton(sf::Vector2i size): RectangleShape((sf::Vector2f)size)
{   
	this->setOrigin((sf::Vector2f)size / 2.f);
	this->setScale(3, 3);
	this->setFillColor(sf::Color::Transparent);
//	this->setOutlineThickness(1);
//	this->setOutlineColor(sf::Color::Red);
	this->setPosition(100, 400);


}

skeleton::~skeleton()
{
}

void skeleton::Init(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

sf::Vector2f skeleton::Velocity()
{
	return velocity;
}
