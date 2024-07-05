#include "resourceManage.h"

resourceManage::resourceManage()
{
    k_path = "../Data/";
    k_texturePath =k_path+ "Textures/";
	k_fontPath = k_path + "Fonts/";
}

resourceManage::~resourceManage()
{
	for (auto it : map_tex) {
		if (it.second != nullptr) delete it.second;
	}
	for (auto it : m_MapFont) {
		if (it.second != nullptr) delete it.second;
	}

}

void resourceManage::addTexture(string name)
{
    sf::Texture* tex = new sf::Texture();;
    tex->loadFromFile( k_texturePath + name+".png");
    auto it = map_tex.find(name);
    if (it != map_tex.end()) return;
    map_tex.insert(pair<string, sf::Texture*>(name, tex));

}

void resourceManage::removeTexture(string name)
{
    auto it = map_tex.find(name);
    if (it == map_tex.end()) return;
    if (it->second != nullptr) delete it->second;
    map_tex.erase(it);
}

sf::Texture* resourceManage::gtTexture(string name)
{
    auto it = map_tex.find(name);
    if (it != map_tex.end()) return it->second;
    sf::Texture* tex = new sf::Texture();
    tex->loadFromFile(k_texturePath + name+".png");
    map_tex.insert(pair<string, sf::Texture*>(name, tex));
    return tex;
}
void resourceManage::addFont(std::string name)
{
	sf::Font* font = new sf::Font();
	font->loadFromFile(k_fontPath + name + ".TTF");

	auto it = m_MapFont.find(name);
	if (it != m_MapFont.end()) {
		return;
	}
	m_MapFont.insert(std::pair<std::string, sf::Font*>(name, font));
}

void resourceManage::removeFont(std::string name)
{
	auto it = m_MapFont.find(name);
	if (it == m_MapFont.end()) {
		return;
	}
	if (it->second != nullptr) delete it->second;
	m_MapFont.erase(it);
}

sf::Font* resourceManage::getFont(std::string name)
{
	auto it = m_MapFont.find(name);
	if (it != m_MapFont.end()) {
		return it->second;
	}
	sf::Font* font = new sf::Font();;
	font->loadFromFile(k_fontPath + name + ".TTF");
	m_MapFont.insert(std::pair<std::string, sf::Font*>(name, font));
	return font;
}