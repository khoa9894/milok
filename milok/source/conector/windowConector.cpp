#include "windowConector.h"

windowConector::windowConector()
{
	m_window = nullptr;
}

void windowConector::setWindow(sf::RenderWindow* window)
{
	m_window = window;
}

sf::RenderWindow* windowConector::getWindow()
{
	return m_window;
}
