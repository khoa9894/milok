#include "background2.h"

void background2::Init()
{
	layer* layer1;
	layer1 = new layer();
	layer1->Init("7", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("8", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("9", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("10", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("11", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("12", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("13", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("14", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("15", 1);
	layerList.push_back(layer1);
}

void background2::Update(float speed)
{
	for (auto it : layerList) {
			it->Update(2);
	}
}

void background2::Render(sf::RenderWindow* window)
{
	for (auto it : layerList) {
		it->Render(*window);
	}
}
