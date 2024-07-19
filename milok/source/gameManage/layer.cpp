#include "layer.h"

void layer::Init(std::string name,int n)
{
	if (n == 1) {
		sf::Texture* tex = resourceManage::GetInstance()->gtTexture(name);
		pi.setTexture(*tex);
		pi1.setTexture(*tex);
		pi1.setScale(2, 2);
		pi.setScale(2, 2);
		pi.setOrigin(sf::Vector2f(tex->getSize().x * 0.5f, tex->getSize().y * 0.5f));
		pi.setPosition(512, 256);
		pi1.setOrigin(sf::Vector2f(tex->getSize().x * 0.5f, tex->getSize().y * 0.5f));
		pi1.setPosition(512 + 512*2, 256);
	}
	if (n == 2) {
		sf::Texture* tex = resourceManage::GetInstance()->gtTexture(name);
		pi.setTexture(*tex);
		pi.setOrigin(sf::Vector2f(tex->getSize().x * 0.5f, tex->getSize().y * 0.5f));
		pi.setPosition(512, 256);
		pi.setScale(2, 2);
	}
}

void layer::Update(float speed)
{
	if (pi.getPosition().x<=-509) {
		pi.setPosition(512+ 512*2, 256);
}
	if (pi1.getPosition().x <= -509) {
		pi1.setPosition(512 + 512 * 2, 256);
	}
	pi.move(-speed, 0);
	pi1.move(-speed, 0);
}

void layer::Render(sf::RenderWindow& window)
{
	window.draw(pi);
	window.draw(pi1);
}
