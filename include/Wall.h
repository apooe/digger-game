#pragma once
#include "StaticObject.h"
#include <SFML/Graphics.hpp>
#include "Digger.h"

class Wall : public StaticObject
{
public:
	//c-tor
	using StaticObject::StaticObject;
	//d-tor
	~Wall();

	//collision between wall and digger
	virtual void collisionObj(Digger& digger) override;
	//collision between wall and wall
	virtual void collisionObj(Wall& wall) override;
	//collision between wall and rock
	virtual void collisionObj(Rock& rock) override;
	//collision between wall and diamond
	virtual void collisionObj(Diamond& diamond) override;
	//collision between wall and present
	virtual void collisionObj(Present& present) override;
	//collision between wall and monster
	virtual void collisionObj(Monster& monster) override;
};

