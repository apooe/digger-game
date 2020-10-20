#pragma once
#include <SFML/Graphics.hpp>
#include"Monster.h"


using sf::Vector2f;
using sf::Keyboard;

class NormalMonster : public Monster
{
public:
	//c-tor 
	using Monster::Monster;



private:
	//set direction of normal monster
	virtual Vector2f setDirection(float deltaTime, const Vector2f diggerPos, const Vector2f monsterPos) override;



};


