#pragma once
#include "../gameManage/resourceManage.h"
enum Tag {
	PLAYER,
	CREEP,
};
class skeleton :public sf::RectangleShape {
public:	skeleton(sf::Vector2i size);
	~skeleton();
	void Init(sf::Vector2f velocity);
	sf::Vector2f Velocity();
	void setTag(Tag tang);
	Tag getTag() {
		return tag;
	}
	bool isAlive() {
		return alive;
	}
	void setAlive(bool alive) {
		this->alive = alive;
	}
	bool isattack() {
		return isAttack;
	}
	void setAttack(bool attack) {
		this->isAttack = attack;
	}
	void setVelocity(sf::Vector2f vec) {
		this->velocity = vec;
	}
private:
	sf::Vector2f velocity;
	Tag tag;
	bool isAttack;
	bool alive;
};