#pragma once
#include <iostream>
#include <map>
#include <string>
#include "../conector/windowConector.h"
using namespace std;
class resourceManage :public CSingleton<resourceManage> {
public: resourceManage();
	  ~resourceManage();
	 void addTexture(string name);
	 void removeTexture(string name);
	 sf::Texture* gtTexture(string name);
	 void addFont(std::string name);
	 void removeFont(std::string name);
	 sf::Font* getFont(std::string name);
private: string k_path;
	   map<string, sf::Texture*> map_tex;
	   map<string, sf::Font*> m_MapFont;
	   string k_texturePath;
	   string k_fontPath;
};