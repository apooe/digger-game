#pragma once
#include <SFML/Graphics.hpp>
#include"Monster.h"

using sf::Vector2f;
using sf::Keyboard;

class SmartMonster : public Monster
{
public:
	//c-tor
	using Monster::Monster;

private:
	//set direction of smart monster
	virtual Vector2f setDirection(float deltaTime, const Vector2f diggerPos, const Vector2f monsterPos) override;
	//smart monster move or not
	bool dontMoveRand;
	//distance between digger and smart monster
	float m_distance;

	sf::Clock m_clock;

};


