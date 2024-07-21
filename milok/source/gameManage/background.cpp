#include "background.h"

void background::Init()
{
	layer* layer1;
	layer1 = new layer();
	layer1->Init("1", 2);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("2", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("3", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("4", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("5", 1);
	layerList.push_back(layer1);
	layer1 = new layer();
	layer1->Init("6", 1);
	layerList.push_back(layer1);
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
	
//	layerList.push_back(layer1);
}

void background::Update(float speed)
{
	for (auto it : layerList) {
		if (it != layerList.front()) {
			it->Update(0.05);

		}

	}
}

void background::Render(sf::RenderWindow *window)
{
	for (auto it : layerList) {
		it->Render(*window);
	}
}
